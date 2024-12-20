#ifndef CHARACTER_H
#define CHARACTER_H

// Character needs access to these includes
#include <SFML/Network.hpp>
#include <SFML/Graphics.hpp>
#include <string>
#include <sstream>
#include <iostream>

// Define Character class
class Character
{

public:
    // Constructor
    Character(std::string name, sf::Vector2f initialPosition, int characterType);

    // Getters and Setters
    int getCharacterType() const;
    void setCharacterType(int type);

    int getLevel() const;
    void setLevel(const int level);

    std::string getName() const;
    void setName(const std::string& name);

    sf::Sprite& getSprite();

    sf::Vector2f getPosition() const;
    float getPositionX() const;   
    float getPositionY() const;
    void setPosition(const sf::Vector2f& position);

    int getState() const;
    void setState(int State);

    void setVelocity(float vx, float vy);
    sf::Vector2f getVelocity() const;

    bool isHost() const;
    void setHost(bool hostStatus);

    // Movement logic
    void move(float deltaX, float deltaY);

    // Multiplayer send/receive logic
    void sendPosition(sf::TcpSocket& socket);
    void receivePosition(const std::string& data);

    // Helper functions for sending/receiving data over the network
    void sendData(sf::TcpSocket& socket, const std::string& data);
    std::string receiveData(sf::TcpSocket& socket);

private:
    std::string name;
    sf::Vector2f position;
    sf::Sprite sprite;

    float velocityX = 0;
    float velocityY = 0;

    bool host;
    int state;
    int characterType;

    int level = 1;

};

extern std::shared_ptr<Character> hostCharacter;
extern std::shared_ptr<Character> clientCharacter;

// There are two instances of Character created no matter what.
// They, however need to be sudo initilized until the player
// chooses a character type.
// Because of this there intilization is done in an actual method
// that happens later on using shared_ptr's.

void initializeCharacter(std::shared_ptr<Character>& character, const std::string& name, const sf::Vector2f& position, int id);

#endif // CHARACTER_H
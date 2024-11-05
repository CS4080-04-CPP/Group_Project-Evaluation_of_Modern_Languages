#ifndef CHARACTER_H
#define CHARACTER_H

#include <SFML/Network.hpp>
#include <SFML/Graphics.hpp>
#include <string>
#include <sstream>
#include <iostream>

class Character
{
private:
    std::string name;
    sf::Vector2f position;
    sf::Sprite sprite;
    float velocityX = 0;
    float velocityY = 0;
    int health;
    bool host;
    int characterType;

public:
    // Constructor
    Character(std::string name, sf::Vector2f initialPosition, int characterType);

    // Getters and Setters
    int getCharacterType() const;
    void setCharacterType(int type);

    std::string getName() const;
    void setName(const std::string& name);

    sf::Sprite& getSprite();

    sf::Vector2f getPosition() const;
    float getPositionX() const;   
    float getPositionY() const;
    void setPosition(const sf::Vector2f& position);

    void setVelocity(float vx, float vy);
    sf::Vector2f getVelocity() const;

    int getHealth() const;
    void setHealth(int health);

    bool isHost() const;
    void setHost(bool hostStatus);

    // Movement logic
    void move(float deltaX, float deltaY);

    // Multiplayer send/receive logic
    void sendPosition(sf::TcpSocket& socket);
    void receivePosition(const std::string& data);

    // Special actions
    void performSpecialAction();

    // Helper functions for sending/receiving data over the network
    void sendData(sf::TcpSocket& socket, const std::string& data);
    std::string receiveData(sf::TcpSocket& socket);

};

extern std::shared_ptr<Character> hostCharacter;
extern std::shared_ptr<Character> clientCharacter;

void initializeCharacter(std::shared_ptr<Character>& character, const std::string& name, const sf::Vector2f& position, int id);

#endif // CHARACTER_H
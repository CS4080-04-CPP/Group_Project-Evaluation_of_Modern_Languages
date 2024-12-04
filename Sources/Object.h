#ifndef OBJECT_H
#define OBJECT_H

// Object needs access to these includes
#include <SFML/Graphics.hpp>
#include <stdexcept>
#include <string>

// Define Object class
class Object
{

public:
    // Constructor and Destructor
    Object(const std::string& imagePath);
    ~Object();

    // Getters
    const sf::Sprite& getSprite() const;

    // Tile Mode is for textures that can be put next to eachother and 'tile'
    // This is not used in this demo because its main purpose is for scalability with resolution
    void toggleTileMode();
    void setTileRepeats(int horizontal, int vertical);

    // Manipuation methods for an object
    void setPosition(float x, float y);
    void setScale(float x, float y);
    void rotate(float angle);
    void centerOrigin();

    // Draws the object to the screen
    void draw(sf::RenderWindow& window);

private:
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Vector2f position;
    sf::Vector2f size;
    bool isTileMode;
    int horizontalRepeats;
    int verticalRepeats;
};

#endif // OBJECT_H
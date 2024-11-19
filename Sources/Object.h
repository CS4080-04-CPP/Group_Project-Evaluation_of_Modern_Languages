#ifndef OBJECT_H
#define OBJECT_H

#include <SFML/Graphics.hpp>
#include <stdexcept>
#include <string>

class Object
{

public:
    Object(const std::string& imagePath);
    ~Object();
    void toggleTileMode();
    const sf::Sprite& getSprite() const;
    void setTileRepeats(int horizontal, int vertical);
    void setPosition(float x, float y);
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
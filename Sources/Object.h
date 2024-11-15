#ifndef Object_H
#define Object_H

class Object
{
public:

    Object(const std::string& imagePath)
        : horizontalRepeats(1), verticalRepeats(1), isTileMode(false)
    {
        if (!texture.loadFromFile(imagePath))
        {
            throw std::runtime_error("Failed to load image.");
        }

        // Set up the sprite with the texture
        sprite.setTexture(texture);
        size = sf::Vector2f(sprite.getGlobalBounds().width, sprite.getGlobalBounds().height);

        collisionEnabled = true; // Enable collision by default
    }

    // Toggle between single object mode and tile mode
    void toggleTileMode()
    {
        isTileMode = !isTileMode;
    }

    const sf::Sprite& getSprite() const { return sprite; }

    // Set how many times the tile repeats
    void setTileRepeats(int horizontal, int vertical)
    {
        horizontalRepeats = horizontal;
        verticalRepeats = vertical;
    }

    // Set the position of the floor starting point
    void setPosition(float x, float y)
    {
        position = { x, y };
        sprite.setPosition(position);
    }

    // Check if this object collides with another
    bool checkCollision(const sf::Sprite& otherSprite) const
    {
        if (!collisionEnabled)
        {
            return false;
        }

        return sprite.getGlobalBounds().intersects(otherSprite.getGlobalBounds());
    }

    // Draw the object (handles both single and tiled mode)
    void draw(sf::RenderWindow& window)
    {
        if (isTileMode)
        {
            // Draw the tile in a grid pattern with specified repeats
            for (int y = 0; y < verticalRepeats; ++y)
            {
                for (int x = 0; x < horizontalRepeats; ++x)
                {
                    // Set the position for each repeated tile
                    sprite.setPosition((position.x + x * size.x)-x, position.y + y * size.y);
                    window.draw(sprite);
                }
            }
        }
        else
        {
            // Draw as a single object
            sprite.setPosition(position);
            window.draw(sprite);
        }
    }

private:
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Vector2f position;
    sf::Vector2f size;
    bool collisionEnabled;
    bool isTileMode;         // Flag to toggle between single and tile mode
    int horizontalRepeats;   // Number of times to repeat horizontally
    int verticalRepeats;     // Number of times to repeat vertically
};

#endif
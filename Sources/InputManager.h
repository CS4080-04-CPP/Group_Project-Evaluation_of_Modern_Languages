#ifndef INPUTMANAGER_HPP
#define INPUTMANAGER_HPP

// InputManager needs access to these includes
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Window.hpp>

// Define InputManager class
class InputManager
{

public:
    // Constructor/Destructor
    InputManager() = default;    // Default is an explicit way to instruct the compiler
    ~InputManager() = default;   // to generate the default constructor for the InputManager class.

    // Function to check if specific keys are pressed
    void processInput(sf::Window& window);

    // Key status
    bool isMoveUp() const { return moveUp; }
    bool isMoveDown() const { return moveDown; }
    bool isMoveLeft() const { return moveLeft; }
    bool isMoveRight() const { return moveRight; }
    bool isJump() const { return jump; }

private:
    bool moveUp = false;
    bool moveDown = false;
    bool moveLeft = false;
    bool moveRight = false;
    bool jump = false;
};

#endif
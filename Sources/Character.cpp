#include "Character.h"

// Constructor
Character::Character(std::string name, sf::Vector2f initialPosition, int characterType)
    : name(std::move(name)), position(initialPosition), health(100), host(false), characterType(characterType)
{
}

void initializeCharacter(std::shared_ptr<Character>& character, const std::string& name, const sf::Vector2f& position, int id)
{
    character->setName(name);          // Set the character's name
    character->setPosition(position);  // Set the character's position
    character->setCharacterType(id);   // Set the character's type
    // Add more initialization logic if needed
}

// Getters and Setters
int Character::getCharacterType() const
{
    return characterType;
}

void Character::setCharacterType(int type)
{
    characterType = type;
}

std::string Character::getName() const
{
    return name;
}

void Character::setName(const std::string& name)
{
    this->name = name;
}

sf::Vector2f Character::getPosition() const
{
    return position;
}

void Character::setPosition(const sf::Vector2f& position)
{
    this->position = position;
}

int Character::getHealth() const
{
    return health;
}

void Character::setHealth(int health)
{
    this->health = health;
}

bool Character::isHost() const
{
    return host;
}

void Character::setHost(bool hostStatus)
{
    this->host = hostStatus;
}

// Movement logic
void Character::move(float deltaX, float deltaY)
{
    this->position.x += deltaX;
    this->position.y += deltaY;
}

// Multiplayer send/receive logic
void Character::sendPosition(sf::TcpSocket& socket)
{
    std::ostringstream dataStream;
    dataStream << "POS:" << position.x << "," << position.y << ";TYPE:" << characterType; // Include position and type

    std::string data = dataStream.str();
    sendData(socket, data);
}

// Special actions
void Character::performSpecialAction()
{
    if (characterType == 1)
    {
        std::cout << name << " (Character A) is performing a special action!" << std::endl;
        // Implement Character A action logic here
    }
    else if (characterType == 2)
    {
        std::cout << name << " (Character B) is performing a special action!" << std::endl;
        // Implement Character B action logic here
    }
    else
    {
        std::cout << name << " has no special action!" << std::endl;
    }
}

// Helper functions for sending/receiving data
void Character::sendData(sf::TcpSocket& socket, const std::string& data)
{

    std::size_t totalSent = 0;
    std::size_t dataLength = data.size();

    while (totalSent < dataLength)
    {
        std::size_t sent;
        if (socket.send(data.c_str() + totalSent, dataLength - totalSent, sent) != sf::Socket::Done)
        {
            std::cout << "Error: Failed to send data\n";
            return;
        }
        totalSent += sent; // Keep track of how much data has been sent
    }

}

std::string Character::receiveData(sf::TcpSocket& socket)
{
    char data[100];
    std::size_t received;
    if (socket.receive(data, sizeof(data), received) != sf::Socket::Done)
    {
        std::cout << "Error: Unable to receive data\n";
        return "";
    }

    std::string receivedData(data, received);

    // Ensure the received data is valid before parsing
    if (!receivedData.empty())
    {
        // Call receivePosition directly with the received data string
        receivePosition(receivedData);
    }

    return receivedData;
}

// Static helper function to parse position data
void Character::receivePosition(const std::string& data)
{
    sf::Vector2f newPosition(0.f, 0.f);
    int newCharacterType = characterType; // Default to current type if not found in the data

    std::stringstream ss(data);
    std::string token;

    while (std::getline(ss, token, ';'))
    {
        if (token.substr(0, 4) == "POS:")
        {
            std::string positionPart = token.substr(4);
            std::stringstream posStream(positionPart);
            std::string xStr, yStr;

            if (std::getline(posStream, xStr, ',') && std::getline(posStream, yStr))
            {
                try
                {
                    newPosition.x = std::stof(xStr);
                    newPosition.y = std::stof(yStr);
                    position = newPosition; // Update character position
                }
                catch (const std::exception& e)
                {
                    std::cout << "Error parsing position: " << e.what() << "\n";
                }
            }
        }
        else if (token.substr(0, 5) == "TYPE:")
        {
            std::string typePart = token.substr(5);
            try
            {
                newCharacterType = std::stoi(typePart);
                characterType = newCharacterType; // Update character type
            }
            catch (const std::exception& e)
            {
                std::cout << "Error parsing character type: " << e.what() << "\n";
            }
        }
    }
}
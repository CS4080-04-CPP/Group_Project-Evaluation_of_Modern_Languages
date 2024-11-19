#include "Main.h"

// Host game logic
void hostGameLogic(Character& character, Character& character2)
{

    // Create a listener to wait for incoming connections
    sf::TcpListener listener;

    // Bind the listener to a port
    if (listener.listen(54000) != sf::Socket::Done)
    {

        std::cout << "Error: Unable to bind the listener to the port\n";
        return;
    }

    std::cout << "Host: Waiting for client connection...\n";

    // Accept an incoming connection
    sf::TcpSocket socket;
    if (listener.accept(socket) != sf::Socket::Done)
    {

        std::cout << "Error: Unable to accept the client connection\n";
        return;
    }

    // Set to non-blocking mode
    socket.setBlocking(false);
    character2.setHost(true);
    character.setHost(false);
    Connected = true;

    std::this_thread::sleep_for(std::chrono::seconds(2));

    while (true)
    {
       
        character2.sendPosition(socket);

        // Buffer for receiving data
        char data[100];
        std::size_t received;
        sf::Socket::Status status = socket.receive(data, sizeof(data), received);

        if (status == sf::Socket::Done)
        {

            std::string receivedData(data, received);
            character.receivePosition(receivedData);
        }
        else if (status == sf::Socket::NotReady)
        {
            // Socket is not ready, wait a bit before retrying
        }
        else
        {

            std::cout << "Error: Unable to receive data, status: " << status << "\n";
            break; // Exitw the loop on error
        }
    }
}

// Client game logic
void connectGameLogic(Character& character, Character& character2)
{

    sf::TcpSocket socket;

    if (socket.connect("127.0.0.1", 54000) != sf::Socket::Done)
    {

        std::cout << "Error: Unable to connect to the host\n";
        return;
    }

    // Set to non-blocking mode
    socket.setBlocking(false);
    character.setHost(false);
    character2.setHost(true);
    Connected = true;

    std::this_thread::sleep_for(std::chrono::seconds(2));

    while (true)
    {       

        // Send character position to the host
        character2.sendPosition(socket);

        // Buffer for receiving data
        char data[100];
        std::size_t received;
        sf::Socket::Status status = socket.receive(data, sizeof(data), received);

        if (status == sf::Socket::Done)
        {

            std::string receivedData(data, received);
            character.receivePosition(receivedData);
        }
        else if (status == sf::Socket::NotReady)
        {

            // Socket is not ready, wait a bit before retrying
        }
        else
        {

            std::cout << "Error: Unable to receive data, status: " << status << "\n";
            break; // Exitw the loop on error
        }
    }
}
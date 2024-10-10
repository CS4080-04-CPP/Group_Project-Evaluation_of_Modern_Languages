#include "Main.h"
#include <SFML/Network.hpp>

using namespace std;

// Function to handle socket hosting
bool hostSocket(sf::TcpListener& listener, unsigned short port)
{
    if (listener.listen(port) != sf::Socket::Done)
    {
        cout << "Error: Unable to start server on port " << port << endl;
        return false;
    }
    cout << "Server is hosting on port " << port << "..." << endl;
    return true;
}

// Function to handle socket connection
bool connectSocket(sf::TcpSocket& socket, const string& ipAddress, unsigned short port)
{
    if (socket.connect(ipAddress, port) != sf::Socket::Done)
    {
        cout << "Error: Unable to connect to server at " << ipAddress << " on port " << port << endl;
        return false;
    }
    cout << "Connected to server at " << ipAddress << " on port " << port << "!" << endl;
    return true;
}

void hostGameLogic()
{

    // Host game logic
    sf::TcpListener listener;
    unsigned short port = 54000;
    if (hostSocket(listener, port))
    {
        // Socket is hosted successfully, waiting for connections...
        sf::TcpSocket client;
        if (listener.accept(client) == sf::Socket::Done)
        {
            cout << "Client connected!" << endl;
            // You can now send/receive data with the client using `client`
        }
    }
}

void connectGameLogic()
{
    // Connect to server logic
    sf::TcpSocket socket;
    unsigned short port = 54000;
    string ipAddress = "127.0.0.1";

    if (connectSocket(socket, ipAddress, port))
    {
        cout << "connection succcesfull";
    }
    else { cout << "Error: " << port << " " << ipAddress; }
}
#include <iostream>
#include <cstring> // For string functions
#include <cstdlib> // For memory allocation

using namespace std;

// Maximum number of nodes (cities)
const int MAX_NODES = 100;

// Structure representing a flight node (city/airport)
struct Node
{
    char name[50];
    struct Edge *neighbors;
};

// Structure representing a flight edge with weight/cost
struct Edge
{
    Node *destination;
    int weight;
    Edge *next;
};

// Structure representing the flight graph
struct FlightGraph
{
    Node *nodes[MAX_NODES];
    int nodeCount;

    FlightGraph()
    {
        nodeCount = 0;
        memset(nodes, 0, sizeof(nodes)); // Initialize nodes array with null pointers
    }

    // Function to create a new node
    Node *createNode(const char *cityName)
    {
        Node *newNode = (Node *)malloc(sizeof(Node));
        strcpy(newNode->name, cityName);
        newNode->neighbors = NULL;
        return newNode;
    }

    // Function to add a directed edge between two nodes with a weight/cost
    void addEdge(Node *from, Node *to, int weight)
    {
        Edge *newEdge = (Edge *)malloc(sizeof(Edge));
        newEdge->destination = to;
        newEdge->weight = weight;
        newEdge->next = from->neighbors;
        from->neighbors = newEdge;
    }

    // Depth-first search (DFS) to check connectivity
    void DFS(Node *start, bool visited[])
    {
        visited[start - nodes[0]] = true; // Mark node as visited
        Edge *edge = start->neighbors;
        while (edge != NULL)
        {
            if (!visited[edge->destination - nodes[0]])
            {
                DFS(edge->destination, visited);
            }
            edge = edge->next;
        }
    }

    // Check if the graph is connected
    bool isConnected()
    {
        bool visited[MAX_NODES] = {false};
        DFS(nodes[0], visited); // Start DFS from the first node
        for (int i = 0; i < nodeCount; i++)
        {
            if (!visited[i])
            {
                return false; // If any node is not visited, graph is not connected
            }
        }
        return true; // All nodes are visited, graph is connected
    }
};

int main()
{
    FlightGraph flightNetwork;

    // Adding nodes to the graph
    Node *cityA = flightNetwork.createNode("City A");
    Node *cityB = flightNetwork.createNode("City B");
    Node *cityC = flightNetwork.createNode("City C");
    Node *cityD = flightNetwork.createNode("City D");
    // Add more nodes as needed

    flightNetwork.nodes[flightNetwork.nodeCount++] = cityA;
    flightNetwork.nodes[flightNetwork.nodeCount++] = cityB;
    flightNetwork.nodes[flightNetwork.nodeCount++] = cityC;
    flightNetwork.nodes[flightNetwork.nodeCount++] = cityD;

    // Adding edges to the graph
    flightNetwork.addEdge(cityA, cityB, 1); // Assuming weight/cost of 1 for simplicity
    flightNetwork.addEdge(cityA, cityC, 1);
    flightNetwork.addEdge(cityB, cityD, 1);
    // Add more edges as needed

    // Checking if the graph is connected
    if (flightNetwork.isConnected())
    {
        cout << "The flight network is connected.\n";
    }
    else
    {
        cout << "The flight network is not connected.\n";
    }

    return 0;
}

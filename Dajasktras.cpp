#include <iostream>
#include <vector>
#include <climits> // Include this header for INT_MAX
#include <set>

using namespace std;
void addEdge(vector<pair<int, int>> adj[], int u, int v, int edgeDistance)
{
    adj[u].push_back(make_pair(v, edgeDistance));
    adj[v].push_back(make_pair(u, edgeDistance));
}

void implementDijakstras(vector<pair<int, int>> adj[], int distance[], int src)
{
    distance[src] = 0;
    set<pair<int, int>> setContainer;

    // firstly iinsert first minimum set inside set as it is [0,0] in our case
    setContainer.insert(make_pair(0, src)); // idea is first store distance and then vertex

    // now set contains our first minimum pair we need vartex from it and get its adjecent nodesas our initial path

    // run loop until set not becomes empty
    while (!setContainer.empty())
    {
        // first vertex is minimum distance vertex by default
        pair<int, int> mimimumDistPair = *(setContainer.begin());
        // now erase that from that set
        setContainer.erase(setContainer.begin());
        // here we hae got minimum distance pair from set so we work on adjecent lists of them
        int vertex = mimimumDistPair.second; // herre we got that vertex
        // use iterator for getting all adjecent vertices if vertex we just retrievde
        for (auto iterator = adj[vertex].begin(); iterator != adj[vertex].end(); ++iterator)
        {
            // herer we have adjList element one by ine
            
        }
    }
}

void printGraph(vector<pair<int, int>> adj[], int vertexCount)
{
    for (int b = 0; b < vertexCount; b++)
    {
        cout << b << "->" << ": ";
        for (auto x : adj[b])
        {
            cout << x.first << " " << x.second << " , ";
        }
        cout << endl;
    }
}
int main()
{
    int vCount = 5;
    vector<pair<int, int>> adj[vCount];
    int distanceOpt[vCount];

    // inatializing all distances to infinity as algorithm says
    for (int i = 0; i < vCount; i++)
    {
        distanceOpt[i] = INT_MAX;
    }
    int src = 0;
    addEdge(adj, 0, 1, 2);
    addEdge(adj, 0, 4, 5);
    addEdge(adj, 1, 2, 1);
    addEdge(adj, 1, 3, 3);
    addEdge(adj, 1, 4, 5);
    addEdge(adj, 2, 3, 12);
    addEdge(adj, 3, 4, 4);

    implementDijakstras(adj, distanceOpt, src);

    // printGraph(adj, vCount);
    return 0;
}
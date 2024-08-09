#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;
#include <map>

void manageTopological(int vertex, stack<int> &st, unordered_map<int, bool> &visited, map<int, vector<int>> &adjList)
{
    // mark node as visited
    visited[vertex] = true;

    for (const auto &item : adjList[vertex])
    {
        // check weather visited or not
        if (!visited[item])
        {
            // make recursive call stacks until end of stack contigueness
            manageTopological(item, st, visited, adjList);//recursive call
        }
    }

    // adding node to stack as it is added last to this call stack as this call stack coming last through recursion
    st.push(vertex);
}
int main()
{
    // vector containing edges
    //  Define the edges of the directed acyclic graph (DAG)
    int vertexCount = 6;
    vector<pair<int, int>> edges;

    // Add edges to the graph
    edges.push_back({0, 1});
    edges.push_back({0, 2});
    edges.push_back({1, 3});
    edges.push_back({1, 4});
    edges.push_back({2, 4});
    edges.push_back({3, 5});
    edges.push_back({4, 5});

    // makeing adjecency list
    map<int, vector<int>> adjList;
    // initialize possible keys
    for (int i = 0; i < vertexCount; i++)
    {
        adjList[i]; // This ensures that each vertex is a key in the map with an eadjListty vector
    }

    for (const auto &edge : edges)
    {
        adjList[edge.first].push_back(edge.second);
    }

    // print adjejency list
    for (const auto &item : adjList)
    {
        cout << "key " << item.first << ":";
        for (const auto &iteminner : item.second)
        {
            cout << iteminner << " ";
        }
        cout << endl;
    }

    // till this we have adjecency list present
    // make stack for ordering elements according to dfs
    stack<int> st;
    // make data strucutre for visited count
    unordered_map<int, bool> visited;

    for (int i = 0; i < vertexCount; i++)
    {
        // make call for each vertex as it is not visited if only
        if (!(visited[i]))
        {
            // means vertex is not visited yet
            manageTopological(i, st, visited, adjList);
        }
    }

    while (!(st.empty()))
    {
        cout << st.top() << endl;
        st.pop();
    }

    return 0;
}
#include <iostream>
using namespace std;
#include <queue>
#include <utility>
#include <algorithm>
#include <map>
#include <vector>
bool isCyclePresent(int current, int parentNode, vector<pair<int, int>> &edges, map<int, vector<int>> &adjList, vector<bool> visited, vector<int> &parent)
{
    // mark node as visited
    visited[current] = true;
    cout << "visited status:" << endl;
    for (int i = 0; i < visited.size(); i++)
    {
        cout << visited[i] << " ";
    }
    cout << endl;
    cout << "current node is " << current << endl;
    for (int iterator : adjList[current])
    {
        // iterate over reursion
        cout << "current element in adj list " << iterator << endl;
        cout << "iterator " << iterator << " " << "parent " << parentNode << endl;
        if (!visited[iterator])
        {
            // not visited make recursive calls for adjList until lost is over
            parent[iterator] = current; // make iteratirs parent if it is strictly not visited
            cout << "parent of " << iterator << "is set to " << current << endl;
            cout << "current parent state:" << endl;
            for (int i = 0; i < parent.size(); i++)
            {
                cout << i << "->" << parent[i];
                cout << endl;
            }
            return isCyclePresent(iterator, current, edges, adjList, visited, parent);
        }

        else if (iterator != parentNode)
        {
            // means node is parent and akready have children and cycle is present
            cout << "inside else if block " << endl;
            return true;
            // this will returrn true as previous call stack return
        }
    }

    // if loop will complete assume as there us no any cycle and return false
    return false;
}
bool checkIsCyclePresentuAINFbFS(int current, vector<bool> &visited, map<int, vector<int>> &adjList)
{
    queue<int> line;
    visited[current] = true;
    line.push(current);
    vector<int> parent(visited.size(), -1);
    parent[current] = -1;
    // find currents adjencency list
    while (!line.empty())
    {
        // extract adjecency list of the current node
        //  this is an appropriate way for adj list
        int popped = line.front();
        line.pop();
        cout << "popped value " << popped << endl;
        // pushing adjecent in line

        for (int iterator : adjList[popped])
        {
            // got an item from popped adj list
            cout << "parent of popped " << parent[popped] << " " << "iterators " << iterator << endl;
            if (!visited[iterator])
            {
                line.push(iterator);
                visited[iterator] = true; // marked as visited
                // popperd value is set as parent value
                parent[iterator] = popped;
                cout << "if executed" << endl;
            }
            else if (parent[popped] != iterator)
            {
                // here we come condition where graph cycle found
                cout << "insid else if" << endl;
                return true;
            }
        }
        //
    }

    return false;
}
int main()
{
    vector<pair<int, int>> edges;
    vector<bool> visited(5, false);
    vector<int> parent(visited.size(), -1);

    map<int, vector<int>> adjList;
    edges.push_back({0, 1});
    edges.push_back({1, 2});
    edges.push_back({2, 3});
    edges.push_back({3, 4});
    edges.push_back({4, 0});

    // making adj list
    for (int i = 0; i < edges.size(); i++)
    {
        adjList[edges[i].first].push_back(edges[i].second);
        adjList[edges[i].second].push_back(edges[i].first);
    }

    for (auto &i : adjList)
    {
        cout << "key: " << i.first << ": ";
        for (auto &j : i.second)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    // parent[0] = -1;
    // cout << "current parent state:" << endl;
    // for (int i = 0; i < parent.size(); i++)
    // {
    //     cout << i << "->" << parent[i];
    //     cout << endl;
    // }
    // cout << "visited status:" << endl;
    // for (int i = 0; i < visited.size(); i++)
    // {
    //     cout << visited[i] << " ";
    // }
    // cout << endl;
    // call recursive function with initial node
    // cout << isCyclePresent(0, -1, edges, adjList, visited, parent);
    cout << checkIsCyclePresentuAINFbFS(0, visited, adjList);
    return 0;
}
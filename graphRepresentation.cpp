#include <iostream>
using namespace std;
#include <string>
#include <queue>
#include <iomanip>
#include <stack>
class GraphStructure
{
public:
    string landMarks[5] = {"Main Building", "Library secti", "Sports sectio", "Parking secti", "Auditorium se"};
    int visited[5] = {};
    int visitedIterator = 0;
    void printGraph(int graphRef[5][5], int rows, int columns)
    {
        cout << "                MB    LS   SP  PAK AUDT" << endl;

        for (int i = 0; i < rows; i++)
        {
            cout << landMarks[i] << " ";
            for (int j = 0; j < columns; j++)
            {

                cout << setw(4) << graphRef[i][j] << " ";
            }
            cout << endl;
        }
    }
    void addPath(int graphRef[5][5], int start, int end)
    {
        if (start >= 0 && start < 5 && end >= 0 && end < 5)
        {
            graphRef[start][end] = 1;
        }
        else
        {
            cout << "enter valid path" << endl;
        }
    }
    bool isVisited(int current)
    {
        for (int i = 0; i < visitedIterator; i++)
        {
            if (visited[i] == current)
            {
                return true;
            }
        }
        return false;
    }
    void dfs(int graphRef[5][5], int startVertex)
    {
        if (startVertex < 0 || startVertex >= 5)
        {
            cout << "Invalid start vertex." << endl;
            return;
        }
        stack<int> stack;
        cout << "DFS starting at " << landMarks[startVertex] << endl;
        stack.push(startVertex);
        visited[visitedIterator] = startVertex;
        startVertex++;
        while (!stack.empty())
        {
            int currentVertex = stack.top();
            stack.pop();
            cout << landMarks[currentVertex] << " ";

            for (int i = 0; i < 5; i++)
            {
                if (graphRef[currentVertex][i] && !isVisited(i))
                {
                    stack.push(i);
                    visited[visitedIterator] = i;
                    visitedIterator++;
                }
            }
        }
    }
    void bfs(int graphRef[5][5], int startVertex)
    {
        if (startVertex < 0 || startVertex >= 5)
        {
            cout << "Invalid start vertex." << endl;
            return;
        }
        visited[visitedIterator] = startVertex;
        visitedIterator++;
        queue<int> queue;
        queue.push(startVertex);
        cout << "BFS traversal starting from " << landMarks[startVertex] << ": ";

        // checking adjecent node about all the landmarks we have avaliable
        while (!queue.empty())
        {
            int currentVertex = queue.front();
            queue.pop();
            cout << landMarks[currentVertex] << " ";
            for (int i = 0; i < 5; i++)
            {
                if (graphRef[currentVertex][i] && !isVisited(i))
                {
                    queue.push(i);
                    visited[visitedIterator] = i;
                    visitedIterator++;
                }
                else
                {
                    // cout << "visited";
                }
            }
        }
        // reset visited array and its iterator to avoid collisions between methods
        visitedIterator = 0;
    }
};

int main()
{
    int path[5][5] = {0};
    GraphStructure gs;
    gs.printGraph(path, 5, 5);
    gs.addPath(path, 0, 4);
    gs.addPath(path, 0, 2);
    gs.addPath(path, 3, 3);
    gs.addPath(path, 1, 4);
    gs.addPath(path, 1, 2);
    gs.printGraph(path, 5, 5);
    gs.bfs(path, 0);
    return 0;
}
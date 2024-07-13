#include <iostream>
#include <vector>
using namespace std;
void returnSubSeqn(vector<int> orignal, int index, vector<int> output, vector<vector<int>> finalAns)
{
    if (index >= orignal.size())
    {
        finalAns.push_back(output);
        return;
    }

    // exclude
    // triying using bst based approach
    returnSubSeqn(orignal, index + 1, output, finalAns);

    // for each exclude we must run include
    int element = orignal[index];
    output.push_back(element);
    returnSubSeqn(orignal, index + 1, output, finalAns);
    for (const auto &row : finalAns)
    {
        for (const auto &element : row)
        {
            cout << element << " ";
        }
        cout << endl;
    }
}
int main()
{
    cout << "success";
    vector<int> inp;
    vector<int> output;
    vector<vector<int>> finalAns;
    inp.push_back(1);
    inp.push_back(2);
    inp.push_back(3);

    returnSubSeqn(inp, 0, output, finalAns);
    return 0;
}
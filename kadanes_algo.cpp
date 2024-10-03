#include <iostream>
#include <vector>
using namespace std;
int getMaxSubarraySum(vector<int> &vec)
{
    int sum = 0;
    int maxVal = 0;

    for (int i = 0; i < vec.size(); i++)
    {
        // check weaher currnet element is selectable or not
        if (sum + vec[i] >= 0)
        {
            // in this case we will select this for next sum concenatne
            sum += vec[i];
            maxVal = max(maxVal, sum);
        }
        else
        {
            maxVal = 0;
        }
    }
    return maxVal;
}
int main()
{
    vector<int> myVec = {-2, -3, 4, -1, -2, 1, 5, -3};
    cout << getMaxSubarraySum(myVec);
    return 0;
}
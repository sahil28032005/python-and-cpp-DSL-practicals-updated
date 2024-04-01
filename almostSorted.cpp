#include <bits/stdc++.h>

using namespace std;


/*
 * Complete the 'almostSorted' function below.
 *
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

void almostSorted(vector<int> arr)
{

    if (std::is_sorted(arr.begin(), arr.end()))
    {
        cout << "yes" << endl;
    }
    else
    {
        int i, j;
        for (i = 0; i < arr.size() - 1; i++)
        {
            for (j = i + 1; j < arr.size(); j++)
            {
                swap(arr[i], arr[j]);
                if (std::is_sorted(arr.begin(), arr.end()))
                {
                    goto endloop;
                }
                else
                {
                    swap(arr[i], arr[j]);
                }
            }
        }

    endloop:
        if (std::is_sorted(arr.begin(), arr.end()))
        {
            cout << "yes" << endl;
            cout << "swap " << i + 1 << " " << j + 1;
            goto finalend;
        }
    }

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] <= arr[i + 1])
        {
            continue;
        }
        else
        {
            int k = i;
            // cout<<i;5,6
            while (arr[k] > arr[k + 1] && k < arr.size()-1)
            {
                k++;
            }
            int b = i, n = k;
            // while (b <= n)
            // {
            //     swap(arr[b], arr[n]);
            //     b++;
            //     n--;
            // }
            // if (std::is_sorted(arr.begin(), arr.end()))
            // {
            //     cout << "yes" << endl;
            //     cout << "reverse " << i + 1 << " " << k + 1;
            //     goto finalend;
            // }
            // else
            // {
            //     b = i, n = k;
            //     while (b != n)
            //     {
            //         swap(arr[b], arr[n]);
            //         b++;
            //         n--;
            //     }
            //     for (int i = 0; i < arr.size(); i++)
            //     {
            //         cout << arr[i] << endl;
            //     }
            // }
            reverse(arr.begin() + i, arr.begin() + k + 1);
                if (is_sorted(arr.begin(), arr.end())) {
                    cout << "yes" << endl;
                    cout << "reverse " << i + 1 << " " << k + 1 << endl;
                    goto finalend;
                } else {
                    // Revert the reverse to keep the original state
                    reverse(arr.begin() + i, arr.begin() + k + 1);
                }
        }
    }
    cout << "no" << endl;
finalend:;
}

int main()
{
    // vector<int> anotherVector = {1, 2, 3, 4, 5,76,18,9};
    vector<int> anotherVector = {1, 5,4,3,2,6};//{1,2,3,4,5,6} 4 /2
    // vector<int> anotherVector = {4,2};
    // vector<int> anotherVector = {3, 1, 2};
    almostSorted(anotherVector);
    return 0;
}

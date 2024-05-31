#include <iostream>
using namespace std;
int partition(int *arr, int start, int end)
{

    int select = arr[start], count = 0, i = start, j = end;
    // cout << "select" << arr[start] << endl;
    // cout << "start" << start << endl;
    for (int i = start; i <= end; i++)
    {
        if (arr[i] < select)
        {
            count += 1;
        }
    }
    // cout << "count = " << count << endl;
    swap(arr[start], arr[count + start]);

    for (int k = start; k <= end; k++)
    {
        for (int f = i; f < start + count; f++)
        {
            if (arr[f] < select)
            {
                i++;
                continue;
            }
            break;
        }
        for (int f = j; f > start + count; f--)
        {
            if (arr[f] > select)
            {
                j--;
                continue;
            }
            break;
        }
        // while (arr[i] < select && i < (start + count))
        // {
        //     i++;
        // }
        // while (arr[j] > select && j > (start + count))
        // {
        //     j--;
        // }
        cout << endl;
        if ((i) < (start + count) && (j) > (start + count))
        {
            swap(arr[i], arr[j]);
            continue;
        }
        else
        {
            break;
        }
    }
    return (start + count);
}
void quickSort(int *arr, int start, int end)
{
    if (start >= end)
    {
        return;
    }
    int partitionNumber = partition(arr, start, end);

    // cout << "no" << partitionNumber << endl;
    quickSort(arr, start, partitionNumber - 1);
    quickSort(arr, partitionNumber + 1, end); // ethun gela (3 ala partition houn)
}
int main()
{
    int arr[7] = {3, 7, 1, 34, 5, 9, 8};
    quickSort(arr, 0, 6);
    cout << "sorted array: " << endl;
    for (int i = 0; i < 7; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
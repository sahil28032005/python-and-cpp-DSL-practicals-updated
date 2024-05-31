#include <iostream>
using namespace std;
int partition(int *arr, int start, int end)
{
    int select = arr[start], count = 0, i = start, j = end;
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        if (arr[i] < select)
        {
            count += 1;
        }
    }
    swap(arr[start], arr[count]);
    for (int k = start; k < sizeof(arr) / sizeof(arr[0]); k++)
    {
        while (arr[i] < select && k < start + count)
        {
            i++;
        }
        while (arr[j] > select && j > start + count)
        {
            j--;
        }
        if (i < start + count && j > start + count)
        {
            swap(arr[i], arr[j]);
        }
    }
    return start + count;
}
void quickSort(int *arr, int start, int end)
{
    if (start >= end)
    {
        return;
    }
    int partitionNumber = partition(arr, start, end);
    quickSort(arr, start, partitionNumber - 1);
    quickSort(arr, partitionNumber + 1, end);
}
int main()
{
    int arr[6] = {3, 7, 1, 5, 9, 8};
    quickSort(arr, 0, 5);
    cout << "sorted array: " << endl;
    for (int i = 0; i < 6; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
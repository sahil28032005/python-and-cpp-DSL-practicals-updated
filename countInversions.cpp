
// by log n through merge sort
// int merge(vector<int> &a, vector<int> &b) {
//   int count = 0;
//   int left = 0, right = 0, k = 0;
//   vector<int> merged(a.size() + b.size());
//   while (left < a.size() && right < b.size()) {
//     if (a[left] > b[right]) {
//       count += a.size() - left + 1; // gets valid pair
//       merged[k] = b[right];
//       right++;
//       k++;
//     } else {
//       merged[k] = a[left];
//       k++;
//       left++;
//     }
//   }
//   while (left < a.size()) {
//     merged[k] = a[left];
//     k += 1;
//     left += 1;
//   }
//   while (right < b.size()) {
//     merged[k] = b[right];
//     k += 1;
//     right += 1;
//   }
// }

// merge thhrough indexes as they are coming
int merge(vector<int> &arr, int low, int mid, int high)
{
    int count = 0;
    vector<int> merged;
    int left = low;
    int right = mid + 1;
    while (left <= mid && right <= high)
    {
        // check weather matching condition found or not
        if (arr[left] > arr[right])
        {
            // we want this pair
            // cout<<"found valid"<<arr[left]<<" "<<arr[right]<<endl;
            merged.push_back(arr[right]);
            count += (mid - left + 1);
            right += 1;
        }
        else
        {
            merged.push_back(arr[left]);
            left += 1;
        }
    }
    while (left <= mid)
    {
        merged.push_back(arr[left]);
        left += 1;
    }
    while (right <= high)
    {
        merged.push_back(arr[right]);
        right += 1;
    }
    for (int i = 0; i < merged.size(); i++)
    {
        arr[low + i] = merged[i];
    }

    // cout<<"count is"<<count<<endl;
    return count;
}

// atual mergesort funtion by recursion

int mergeSort(vector<int> &arr, int low, int high)
{
    // calculate mid first
    int count = 0;

    // define base case here
    if (low >= high)
    {
        // do some logic for return
        // cout<<"returning"<<endl;
        return count;
    }

    int mid = (low + high) / 2;
    // cout<<"current mid is"<<mid<<endl;

    count += mergeSort(arr, low, mid);
    // cout<<"call for mide +1 is"<<mid+1<<endl;
    count += mergeSort(arr, mid + 1, high);
    count += merge(arr, low, mid, high); // will get 1 first time

    return count;
}

// by brute force
int returnPairCount(vector<int> &a, int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            // cheking weather a[i]<a[j] so that count will increased
            if (a[i] > a[j])
            {
                count += 1;
            }
        }
    }

    return count;
}
int numberOfInversions(vector<int> &a, int n)
{
    // Write your code here.
    return mergeSort(a, 0, n - 1);
}
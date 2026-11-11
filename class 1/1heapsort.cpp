#include <iostream>
#include <algorithm>
using namespace std;

// Restore the max-heap property for the heap arr[0..end], starting at root
void siftDown(int arr[], int root, int end)
{
    while(true)
    {
        int left = 2*root + 1;
        int right = 2*root + 2;
        int larger = root;

        if(left <= end && arr[left] > arr[larger])
            larger = left;
        if(right <= end && arr[right] > arr[larger])
            larger = right;

        if(larger == root)
            break;

        swap(arr[root], arr[larger]);
        root = larger;
    }
}

int main()
{
    int n;
    cout << "enter the size of the array : ";
    cin >> n;
    int arr[n];
    cout << "enter the elements : ";
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    // Phase 1: build max-heap
    for(int i = n/2 - 1; i >= 0; i--)
        siftDown(arr, i, n-1);

    // Phase 2: repeatedly move the max to the end and shrink the heap
    for(int end = n-1; end > 0; end--)
    {
        swap(arr[0], arr[end]);
        siftDown(arr, 0, end-1);
    }

    cout << "sorted array : ";
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
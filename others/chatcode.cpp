#include <iostream>
using namespace std;

int n;

int lis(int arr[], int i, int prev)
{
    // We have checked all elements
    if(i == n)
        return 0;

    // Don't take arr[i]
    int ans1 = lis(arr, i + 1, prev);

    // Take arr[i] if it is greater than the previous element
    int ans2 = 0;

    if(prev == -1 || arr[i] > arr[prev])
        ans2 = 1 + lis(arr, i + 1, i);

    // Return the better choice
    return max(ans1, ans2);
}

int main()
{
    cin >> n;

    int arr[n];

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "LIS : " << lis(arr, 0, -1) << endl;

    return 0;
}
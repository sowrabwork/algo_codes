#include <iostream>
#include <vector>
using namespace std;
void heapify(vector<int> &arr, int i)
{
    int l = 2 * i + 1;
    int r = l + 1;
    if (l < arr.size() && arr[l] > arr[i])
    {
        swap(arr[i], arr[l]);
        heapify(arr, l);
    }
    if (r < arr.size() && arr[r] > arr[i])
    {
        swap(arr[i], arr[r]);
        heapify(arr, r);
    }
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = n / 2; i >= 0; i--)
    {
        heapify(arr, i);
    }
    vector<int> ans;
    int end = arr.size() - 1;
    for (int i = 0; i < n; i++)
    {
        swap(arr[0], arr[end]);
        ans.push_back(arr[end]);
        end--;
        arr.pop_back();
        heapify(arr, 0);
    }

    for (int x : ans)
        cout << x << " ";
    cout << endl;
}
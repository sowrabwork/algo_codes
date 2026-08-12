#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"enter the size of the array : ";
    cin>>n;
    int arr[n];
    cout<<"enter the elements : ";
    for(int i=0;i<n;i++)
    cin>>arr[i];
    int end=n-1;
    while(end!=0)
    {
        int root=0;
        swap(arr[0],arr[end]);
        end--;
        int left=2*root+1;
        int right=2*root+2;
        while(true)
        {
            int left = 2 * root + 1;
            int right = 2 * root + 2;

            if(left >= end)
                break;

            int larger = left;

            if(right < end && arr[right] > arr[left])
                larger = right;

            if(arr[larger] <= arr[root])
                break;

            swap(arr[root], arr[larger]);
            root = larger;
        }
    }
    cout<<"sorted array : ";
    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";
    cout<<endl;
}
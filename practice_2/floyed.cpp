#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<vector<int>> arr(n,vector<int>(n));
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
    cin>>arr[i][j];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<n;k++)
            {
                arr[j][k]=min(arr[j][k],arr[j][i]+arr[i][k]);
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}
#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int num=1;
    int r=0;
    int c=n/2;
    vector<vector<int>> arr(n,vector<int>(n,-1));
    while(num<=n*n)
    {
        if(arr[r][c]!=-1)
        {
            r+=2;
            c--;
        }
        r=(r+n)%n;
        c=(c+n)%n;
        arr[r][c]=num;
        num++;
        r--;
        c++;
        r=(r+n)%n;
        c=(c+n)%n;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        cout<<arr[i][j]<<" ";
        cout<<endl;
    }
}
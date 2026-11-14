#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<vector<int>> arr(n,vector<int>(n,0));
    int num=1;
    int r=0;
    int c=n/2;
    while( num<=n*n)
    {
        if(arr[r][c]==0)
        {
            arr[r][c]=num;
            num++;
            r--;
            c++;
        }
        else 
        {
            r+=2;
            c--;
        }
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
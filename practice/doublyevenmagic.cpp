#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<vector<int>> arr(n,vector<int>(n,-1));
    int num=1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i%4==j%4 || i%4+j%4==3)
            {
                arr[i][j]=num;
            }
            num++;
        }
    }
    num=1;
    for(int i=n-1;i>=0;i--)
    {
        for(int j=n-1;j>=0;j--)
        {
            if(arr[i][j]==-1)
            {
                arr[i][j]=num ;
            }
            num++;
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
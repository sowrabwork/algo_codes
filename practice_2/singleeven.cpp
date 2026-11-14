#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int m;
    cin>>m;
    int n=m/2;
    vector<vector<int>> a(n,vector<int>(n,0));
    vector<vector<int>> b(n,vector<int>(n,0));
    vector<vector<int>> c(n,vector<int>(n,0));
    vector<vector<int>> d(n,vector<int>(n,0));
    int row=0;
    int col=n/2;
    int num=1;
    while(num<=n*n)
    {
        if(a[row][col]==0)
        {
            a[row][col]=num;
            row--;
            col++;
            num++;
        }
        else
        {
            row+=2;
            col--;
        }
        row=(row+n)%n;
        col=(col+n)%n;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            b[i][j]=a[i][j]+n*n;
            c[i][j]=b[i][j]+n*n;
            d[i][j]=c[i][j]+n*n;
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m/4;j++)
        {
            if(i == n/2)
            swap(a[i][j+1],d[i][j+1]);
            else
            swap(a[i][j],d[i][j]);
        }
        for(int j=0;j<m/4-1;j++)
        {
            swap(c[i][n-j-1],b[i][n-j-1]);
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        cout<<a[i][j]<<" ";
        for(int j=0;j<n;j++)
        cout<<c[i][j]<<" ";
        cout<<endl;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        cout<<d[i][j]<<" ";
        for(int j=0;j<n;j++)
        cout<<b[i][j]<<" ";
        cout<<endl;
    }

}
#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int m=n/2;
    vector<vector<int>> A(m,vector<int>(m,0));
    vector<vector<int>> B(m,vector<int>(m,0));
    vector<vector<int>> C(m,vector<int>(m,0));
    vector<vector<int>> D(m,vector<int>(m,0));
    int num=1;
    int r=0,c=m/2;
    while(num<=m*m)
    {
        if(A[r][c]!=0)
        {
            r+=2;
            c--;
        }
        r=(r+m)%m;
        c=(c+m)%m;
        A[r][c]=num;
        num++;
        r--;
        c++;
        r=(r+m)%m;
        c=(c+m)%m;
    }
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<m;j++)
        {
            B[i][j]=A[i][j]+m*m;
            C[i][j]=B[i][j]+m*m;
            D[i][j]=C[i][j]+m*m;
        }
    }
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n/4;j++)
        {
            if(i==n/4)
            {
                swap(A[i][j+1],D[i][j+1]);
            }
            else
            {
                swap(A[i][j],D[i][j]);
            }
        }
    }
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n/4-1;j++)
        {
            swap(B[i][j],C[i][j]);
        }
    }
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<A[i][j]<<" ";
        }
        for(int j=0;j<m;j++)
        {
            cout<<C[i][j]<<" ";
        }
        cout<<endl;
    }
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<D[i][j]<<" ";
        }
        for(int j=0;j<m;j++)
        {
            cout<<B[i][j]<<" ";
        }
        cout<<endl;
    }
}
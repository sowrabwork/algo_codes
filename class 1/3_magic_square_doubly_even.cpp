#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"enter the value of n : ";
    cin>>n;
    int arr[100][100]={0};
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
            if(arr[i][j]==0)
            {
                arr[i][j]=num;
            }
            num++;
        }
    }
    int highlen=to_string(n*n).length();
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            int numlen=to_string(arr[i][j]).length();
            for(int i=0;i<highlen-numlen;i++)
            cout<<" ";
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}
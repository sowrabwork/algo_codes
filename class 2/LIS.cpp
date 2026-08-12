#include<iostream>
using namespace std;
int dp[1000];
int lis(int arr[],int idx)
{
    if(dp[idx]!=-1)
    {
        return dp[idx];
    }
    int ans=1;
    for(int j=0;j<idx;j++)
    {
        if(arr[j]<arr[idx])
        {
            ans=max(ans,1+lis(arr,j));
        }
    }
    return dp[idx]=ans;
}


int main()
{
    fill(&dp[0],&dp[0]+1000,-1);
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];

    int ans=0;
    for(int i=0;i<n;i++)
    {
        ans=max(ans,lis(arr,i));
    }

    cout<<"LIS : "<<ans<<endl;

}
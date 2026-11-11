#include<iostream>
using namespace std;
int dp[1000];
int lis(string str,int idx)
{
    if(dp[idx]!=-1)
    return dp[idx];
    int ans=1;
    for(int i=0;i<idx;i++)
    {
        if(str[idx]>str[i])
        ans=max(ans,1+lis(str,i));
    }
    return dp[idx]=ans;
}
int main()
{
    fill(&dp[0],&dp[0]+1000,-1);
    string str;
    cin>>str;
    int ans=0;
    for(int i=0 ;i<str.size();i++)
    ans=max(ans,lis(str,i));
    cout<<ans<<endl;
}
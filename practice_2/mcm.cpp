#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> dims;
int dp[1000][1000];
int mcm(int st,int end)
{
    if(st==end)
    return 0;
    if(dp[st][end]!=-1)
    return dp[st][end];
    int ans=INT_MAX;
    for(int i=st;i<end;i++)
    {
        ans=min(ans,mcm(st,i)+mcm(i+1,end)+dims[st-1]*dims[i]*dims[end]);
    }
    return dp[st][end]=ans;
}


int main()
{
    fill(&dp[0][0],&dp[0][0]+1000*1000,-1);
    int n;
    cin>>n;
    for(int i=0;i<n+1;i++)
    {
        int temp;
        cin>>temp;
        dims.push_back(temp);
    }
    cout<<mcm(1,n)<<endl;

}
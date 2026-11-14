#include<iostream>
#include<vector>
using namespace std;
struct item
{
    int val;
    int weight;
};
int dp[1000][1000];
int func(vector<item> items,int khali,int curdex)
{
    if(khali==0)
    return 0;
    if(curdex==-1)
    return 0;
    if(dp[khali][curdex]!=-1)
    return dp[khali][curdex];
    int ans1=func(items,khali,curdex-1);
    int ans2=0;
    if(khali>=items[curdex].weight)
    ans2=func(items,khali-items[curdex].weight,curdex-1)+items[curdex].val;
    return dp[khali][curdex]=max(ans1,ans2);
}


int main()
{
    fill(&dp[0][0],&dp[0][0]+1000*1000,-1);
    int n,capa;
    cin>>n>>capa;
    vector<item> items(n);
    for(int i=0;i<n;i++)
    cin>>items[i].weight>>items[i].val;
    cout<<func(items,capa,n-1)<<endl;
}
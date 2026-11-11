#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct item
{
    int weight;
    int profit;
};
int dp[1000][1000];

int func(vector<item> &items,int i,int capacity)
{
    if(capacity==0)
    return 0;
    if(i<0)
    return 0;
    if(dp[i][capacity]!=-1)
    return dp[i][capacity];
    int ans1=func(items,i-1,capacity);
    int ans2=0;
    if(capacity>=items[i].weight)
    ans2=items[i].profit+func(items,i-1,capacity-items[i].weight);
    return dp[i][capacity]=max(ans1,ans2);
}

int main()
{
    fill(&dp[0][0],&dp[0][0]+1000*1000,-1);
    int n,capacity;
    cin>>n>>capacity;
    vector<item> items(n);
    for(int i=0;i<n;i++)
    cin>>items[i].weight>>items[i].profit;
    cout<<"max profit "<<func(items,n-1,capacity)<<endl;

}
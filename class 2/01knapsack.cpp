#include<iostream>
using namespace std;

struct item{
    int profit;
    int weight;
};

int dp[1000][1000];

int func(item items[],int i,int capacity)
{
    if(capacity==0)
    return 0;
    if(i<0)
    return 0;
    if(dp[i][capacity]!=-1)
    return dp[i][capacity];
    int ans1=func(items,i-1,capacity);
    int ans2=0;
    if(capacity-items[i].weight>=0)
    ans2=func(items,i-1,capacity-items[i].weight)+items[i].profit;
    return dp[i][capacity]=max(ans1,ans2);
}


int main()
{
    fill(&dp[0][0],&dp[0][0]+1000*1000,-1);
    int capacity,n;
    cout<<"enter the capacity and item count : ";
    cin>>capacity>>n;
    item items[n];
    cout<<"enter the weight of the items: "<<endl;
    for(int i=0;i<n;i++)
    cin>>items[i].weight;
    cout<<"enter the profit of the items:"<<endl;
    for(int i=0;i<n;i++)
    cin>>items[i].profit;

    cout<<"MAX PROFIT : "<<func(items,n-1,capacity)<<endl;
    
}
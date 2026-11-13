#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int dp[1000][1000];
vector<int> dims;
int mcm(int st,int end)
{
    if(st==end)
    return 0;
    if(dp[st][end]!=-1)
    return dp[st][end];
    int minans=INT_MAX;
    for(int i=st;i<end;i++)
    {
        minans=min(minans,
            mcm(st,i)+mcm(i+1,end)+dims[st-1]*dims[i]*dims[end]);
    }
    return dp[st][end]=minans;
}

int main()
{
    fill(&dp[0][0],&dp[0][0]+1000*1000,-1);
    int n;
    cout<<"enter the number of matrix: ";
    cin>>n;
    for(int i=0;i<n+1;i++)
    {
        int temp;
        cin>>temp;
        dims.push_back(temp);
    }
    cout<<"total cost: "<<mcm(1,n)<<endl;
}
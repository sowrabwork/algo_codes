#include<iostream>
#include<vector>
using namespace std;
int dp[1000][1000];
int func(vector<vector<int>> &cost,vector<int> remaining,int curDex)
{
    int ansNew=0;
    if(remaining.empty())
    return 0;
    int ans=1000000;
    for(int i=0;i<remaining.size();i++)
    {
        vector<int> remainingCopy = remaining;
        if(remaining.size()==1)
        {
            ansNew=cost[remainingCopy[0]][0];
        }
        remainingCopy.erase(remainingCopy.begin()+i);
        ansNew+=func(cost,remainingCopy,remaining[i])+cost[curDex][remaining[i]];
        ans=min(ans,ansNew);
    }

    return ans;
}


int main()
{
    fill(&dp[0][0],&dp[0][0]+1000*1000,-1);
    int n;
    cin>>n;
    vector<vector<int>> arr(n,vector<int>(n));
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
    cin>>arr[i][j];
    vector<int> remaining;
    for(int i=1;i<n;i++)
    remaining.push_back(i);
    cout<<"min cost : "<<func(arr,remaining,0)<<endl;

}

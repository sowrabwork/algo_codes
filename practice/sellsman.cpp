#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using  namespace std;
int func(vector<vector<int>> &cost,vector<int> remaining,int currdex)
{
    if(remaining.size()==0)
    return cost[currdex][0];
    int ans=INT_MAX;
    for(int i=0;i<remaining.size();i++)
    {
        vector<int> remainingcopy=remaining;
        remainingcopy.erase(remainingcopy.begin()+i);
        ans=min(ans,func(cost,remainingcopy,remaining[i])+cost[currdex][remaining[i]]);
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    vector<vector<int>> cost(n,vector<int>(n,INT_MAX));
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
    cin>>cost[i][j];
    vector<int> remaining;
    for(int i=1;i<n;i++)
    remaining.push_back(i);
    cout<<"mincost"<<func(cost,remaining,0)<<endl;
}
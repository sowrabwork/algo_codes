#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;
int func(vector<vector<int>> cost,vector<int> remaining,int curdex)
{
   if(remaining.size()==0)
   return cost[curdex][0];
   int ans=INT_MAX;
   for(int i=0;i<remaining.size();i++)
   {
    vector<int> remainingcopy=remaining;
    remainingcopy.erase(remainingcopy.begin()+i);
        ans=min(ans,func(cost,remainingcopy,remaining[i])+cost[curdex][remaining[i]]);
   }
   return ans;

}
int main()
{

    int n;
    cin>>n;
    vector<vector<int>> cost(n,vector<int>(n));
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
    cin>>cost[i][j];
    vector<int> remaining;
    for(int i=1;i<n;i++)
    remaining.push_back(i);
    cout<<func(cost,remaining,0);
}
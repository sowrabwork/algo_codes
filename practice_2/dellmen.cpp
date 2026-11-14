#include<iostream>
#include<climits>
#include<vector>
using namespace std;
struct edge
{
    long long st;
    long long end;
    long long weight;
};

int main()
{
    long long v,e;
    cin>>v>>e;
    vector<edge> edges(e);
    for(long long i=0;i<e;i++)
    cin>>edges[i].st>>edges[i].end>>edges[i].weight;
    vector<long long> cost(v,INT_MAX);
    cost[0]=0;
    for(long long i=0;i<v-1;i++)
    {
        for(long long j=0;j<e;j++)
        {
            if(cost[edges[j].st]!=INT_MAX)
            cost[edges[j].end]=min(cost[edges[j].st]+edges[j].weight,cost[edges[j].end]);
        }
    }
    for(long long x:cost)
    cout<<x<<endl;
}
#include<iostream>
#include<vector>
#include<climits>
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
    vector<vector<long long>> adjacency(v,vector<long long>(v,INT_MAX));
    for(long long i=0;i<e;i++)
    adjacency[edges[i].st][edges[i].end]=edges[i].weight;
    vector<bool> visited(v,false);
    visited[0]=true;
    long long count=1;
    vector<long long> cost(v,INT_MAX);
    cost[0]=0;
    long long now_at=0;
    while(count<v)
    {
        for(long long i=0;i<v;i++)
        {
            cost[i]=min(cost[i],cost[now_at]+adjacency[now_at][i]);
        }
        now_at=-1;
        long long mn=INT_MAX;
        for(long long i=0;i<v;i++)
        {
            if(cost[i]<mn && !visited[i])
            {
                now_at=i;
                mn=cost[i];
            }
        }
        if(now_at==-1)
        break;
        visited[now_at]=true;
        count++;
    }
    for(long long x:cost)
    cout<<x<<endl;
}
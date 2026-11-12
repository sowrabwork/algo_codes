#include<iostream>
#include<vector>
#include<climits>
using namespace std;
struct edge
{
    int st;
    int end;
    int weight;
};

int main()
{
    int v,e;
    cin>>v>>e;
    vector<edge> edges(e);
    for(int i=0;i<e;i++)
    cin>>edges[i].st>>edges[i].end>>edges[i].weight;
    vector<vector<int>> adjacencymatrix(v,vector<int>(v,INT_MAX));   
    for(int i=0;i<e;i++)
    adjacencymatrix[edges[i].st][edges[i].end]=edges[i].weight;
    vector<long long> cost(v,INT_MAX);
    cost[0]=0;
    int now_at=0;
    int count=1;
    vector<bool> visited(v,false);
    visited[0]=true;
    while(count<v)
    {
        for(int i=0;i<v;i++)
        {
            if(cost[now_at]!=INT_MAX && cost[i]>cost[now_at]+adjacencymatrix[now_at][i])
            {
                cost[i]=cost[now_at]+adjacencymatrix[now_at][i];
            }
        }
        int mn=INT_MAX;
        now_at=-1;
        for(int i=0;i<v;i++)
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
    if(now_at!=-1)
    for(int i=0;i<v;i++)
    cout<<i<<" : "<<cost[i]<<endl;
}
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
    vector<long long> cost(v,INT_MAX);
    cost[0]=0;
    for(int i=0;i<v-1;i++)
    {
        bool updated=false;
        for(int j=0;j<e;j++)
        {
            if(cost[edges[j].st]!=INT_MAX && cost[edges[j].end]>cost[edges[j].st]+edges[j].weight)
            {
                cost[edges[j].end]=cost[edges[j].st]+edges[j].weight;
                updated=true;
            }
        }
        if(!updated)
        break;
    }
    for(int i=0;i<v;i++)
    cout<<i<<":"<<cost[i]<<endl;
}
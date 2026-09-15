#include<iostream>
#include<vector>
using namespace std;

struct edge
{
    int st,end,weight;
    edge(int st,int end,int weight)
    {
        this->st=st;
        this->end=end;
        this->weight=weight;
    }
};


int main()
{
    int v,e;
    cout<<"enter the number of vertex and edges: ";
    cin>>v>>e;
    vector<edge> edges;
    vector<int> cost(v,100000);
    cost[0]=0;
    cout<<"enter the edges: "<<endl;
    for(int i=0;i<e;i++)
    {
        int st,end,weight;
        cin>>st>>end>>weight;
        edges.push_back(edge(st,end,weight));
    }



    for(int i=0;i<v-1;i++)
    {
        bool updated=false;
        for(int j=0;j<e;j++)
        {
            if(cost[edges[j].end]>cost[edges[j].st]+edges[j].weight && cost[edges[j].st]!=100000)
            {
                cost[edges[j].end]=cost[edges[j].st]+edges[j].weight;
                updated=true;
            }
        }
        if(!updated)
        {
            break;
        }
    }
    cout<<"minimum distances : "<<endl;
    for(int i=0;i<v;i++)
    {
        cout<<i<<" : "<<cost[i]<<endl;
    }
}
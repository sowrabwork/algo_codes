#include<iostream>
#include<climits>
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
    cout<<"enter the number of vertex and edges: "<<endl;
    int v,e;
    cin>>v>>e;
    cout<<"enter 0 for underected graph and 1 for derected graph: ";
    int directed;
    cin>>directed;
    cout<<"enter the edges: "<<endl;
    vector<edge> edges;
    for(int i=0;i<e;i++)
    {
        int st,end,weight;
        cin>>st>>end>>weight;
        edges.push_back(edge(st,end,weight));
    }
    if(!directed)
    {
        for(int i=0;i<e;i++)
        {
            edges.push_back(edge(edges[i].end,edges[i].st,edges[i].weight));
        }
    }
    vector<vector<int>> adjecencyMatrix(v,vector<int>(v,INT_MAX));
    for(int i=0;i<edges.size();i++)
    {
        adjecencyMatrix[edges[i].st][edges[i].end]=edges[i].weight;
    }
    vector<bool> visited(v,false);
    visited[0]=true;
    vector<int> costArr(v,INT_MAX);
    costArr[0]=0;
    int count=1;
    int nowAt=0;
    while(count<v)
    {
        for(int i=0;i<v;i++)
        {
            if(adjecencyMatrix[nowAt][i]!=INT_MAX 
                && costArr[i]>costArr[nowAt]+adjecencyMatrix[nowAt][i])
                {
                    costArr[i]=costArr[nowAt]+adjecencyMatrix[nowAt][i];
                }
        }
        int mn=INT_MAX;
        nowAt=-1;
        for(int i=0;i<v;i++)
        {
            if(costArr[i]<mn && !visited[i])
            {
                mn=costArr[i];
                nowAt=i;
            }
        }
        if(nowAt==-1)
        break;
        visited[nowAt]=true;
        count++;
    }

    if(nowAt!=-1)
    for(int i=0;i<v;i++)
    {
        cout<<i<<" : "<<costArr[i]<<endl;
    }
}
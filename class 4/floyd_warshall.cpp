#include<iostream>
#include<windows.h>
#include<vector>
#include<climits>
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
    SetConsoleOutputCP(CP_UTF8);
    int v,e;
    cout<<"enter the number of vertices and edges: ";
    cin>>v>>e;
    cout<<"enter 1 if the graph is derected otherwise enter 0: ";
    int derected;
    cin>>derected;
    vector<edge> edges;
    cout<<"enter the edges: "<<endl;
    for(int i=0;i<e;i++)
    {
        int st,end,weight;
        cin>>st>>end>>weight;
        edges.push_back(edge(st,end,weight));
    }
    if(!derected)
    {
        for(int i=0;i<e;i++)
        {
            edges.push_back(edge(edges[i].end,edges[i].st,edges[i].weight));
        }
    }
    vector<vector<int>> adjacencyMatrix(v,vector<int>(v,INT_MAX));
    for(int i=0;i<edges.size();i++)
    {
        if(adjacencyMatrix[edges[i].st][edges[i].end]>edges[i].weight)
        adjacencyMatrix[edges[i].st][edges[i].end]=edges[i].weight;
    }
    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
        {
            for(int k=0;k<v;k++)
            {
                if(j==i || k==i || j==k)
                {
                    continue;
                }
                else
                {
                    if(adjacencyMatrix[j][i]!=INT_MAX &&adjacencyMatrix[i][k]!=INT_MAX 
                        && adjacencyMatrix[j][k]>adjacencyMatrix[j][i]+adjacencyMatrix[i][k])
                    {
                        adjacencyMatrix[j][k]=adjacencyMatrix[j][i]+adjacencyMatrix[i][k];
                    }
                }
            }
        }
    }
    cout<<"here is the final adjacency matrix: "<<endl;
    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
        {
            if(adjacencyMatrix[i][j]>=0)
            {
                cout<<" ";
            }
            if(i==j)
            {
                cout<<"0 ";
            }
            else if((adjacencyMatrix[i][j]==INT_MAX))
            {
                cout<<"∞ ";
            }
            else
            {
                cout<<adjacencyMatrix[i][j]<<" ";
            }
        }
        cout<<endl;
    }
}
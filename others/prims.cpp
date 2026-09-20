#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>
using namespace std;

struct edge
{
    int st,end,weight;
    bool selected=false;
    edge(int st,int end,int weight)
    {
        this->st=st;
        this->end=end;
        this->weight=weight;
    }
};
vector<edge> edges;
bool compair(int a,int b)
{
    return edges[a].weight<edges[b].weight;
}

int main()
{
    cout<<"enter the number of vertex and edges: ";
    int v,e;
    cin>>v>>e;
    cout<<"enter the edges: "<<endl;
    for(int i=0;i<e;i++)
    {
        int st,end,weight;
        cin>>st>>end>>weight;
        edges.push_back(edge(st,end,weight));
        edges.push_back(edge(end,st,weight));
    }
    vector<vector<int>> adjacencyMatrix(v,vector<int>(v,INT_MAX));
    for(int i=0;i<edges.size();i++)
    {
        adjacencyMatrix[edges[i].st][edges[i].end]=edges[i].weight;
    }
    string MST="0";
    int currNode=0;
    vector<bool> nodesVisited(v,false);
    int visitedcnt=1;
    nodesVisited[0]=true;
    nodesVisited.push_back(0);
    vector<int> sortedEdge;
    vector<int> ans;
    ans.push_back(0);
    while(visitedcnt<v)
    {
        for(int i=0;i<edges.size();i++)
        {
            if(edges[i].st==currNode)
            {
                sortedEdge.push_back(i);
            }
        }
        sort(sortedEdge.begin(),sortedEdge.end(),compair);
        bool found=false;
        for(int i=0;i<sortedEdge.size();i++)
        {
            if(nodesVisited[edges[sortedEdge[i]].st] && !nodesVisited[edges[sortedEdge[i]].end])
            {
                nodesVisited[edges[sortedEdge[i]].end]=true;
                ans.push_back(edges[sortedEdge[i]].end);
                currNode=edges[sortedEdge[i]].end;
                visitedcnt++;
                break;
            }
        }
    }
    for(int i=0;i<ans.size();i++)
    cout<<ans[i]<<" ";
    cout<<endl;

}
#include<iostream>
#include<vector>
#include<algorithm>
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
vector<edge> edges;
bool compairator(int a,int b)
{
    return edges[a].weight<edges[b].weight;
}
int main()
{
    int v,e;
    cout<<"enter the number of vertices and edges: ";
    cin>>v>>e;
    cout<<"enter the edges: "<<endl;
    for(int i=0;i<e;i++)
    {
        int st,end,weight;
        cin>>st>>end>>weight;
        edges.push_back(edge(st,end,weight));
        edges.push_back(edge(end,st,weight));
    }
    vector<bool> visitedNode(v,false);
    vector<int> sortedEdge;
    vector<int> ans;
    visitedNode[0]=true;
    ans.push_back(0);
    bool found;
    int mstCost=0;
    while(ans.size()<v)
    {
        for(int i=0;i<edges.size();i++)
        {
            if(edges[i].st==ans.back())
            {
                sortedEdge.push_back(i);
            }
        }
        sort(sortedEdge.begin(),sortedEdge.end(),compairator);
        found=false;
        for(int i=0;i<sortedEdge.size();i++)
        {
            if(!visitedNode[edges[sortedEdge[i]].end])
            {
                ans.push_back(edges[sortedEdge[i]].end);
                visitedNode[edges[sortedEdge[i]].end]=true;
                mstCost+=edges[sortedEdge[i]].weight;
                found=true;
                break;
            }
        }
        if(!found)
        {
            cout<<"the graph is disconnected"<<endl;
            break;
        }
    }
    if(found)
    {
        for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
        cout<<endl;
        cout<<"total cost: "<<mstCost<<endl;
    }
}

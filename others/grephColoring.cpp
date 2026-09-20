#include<iostream>
#include<vector>
using namespace std;
struct edge
{
    int st,end;
    edge(int st,int end)
    {
        this->st=st;
        this->end=end;
    }
};

int main()
{
    cout<<"enter the number of vartices and edges: ";
    int v,e;
    cin>>v>>e;
    cout<<"enter the edges: "<<endl;
    vector<edge> edges;
    for(int i=0;i<e;i++)
    {
        int st,end;
        cin>>st >>end;
        edges.push_back(edge(st,end));
    }
    cout<<"enter the number of color: ";
    int numClr;
    cin>>numClr;
    vector<string> colors(numClr);
    cout<<"enter the colors: "<<endl;
    for(int i=0;i<numClr;i++)
    {
        cin>>colors[i];
    }
    vector<vector<int>> adjacencyMatrix(v,vector<int>(v,0));
    for(int i=0;i<e;i++)
    {
        adjacencyMatrix[edges[i].st][edges[i].end]=1;
        adjacencyMatrix[edges[i].end][edges[i].st]=1;
    }
    vector<string> nodecolors(v,"none");
    vector<string> solution;
    for(int i=0;i<v;i++)
    {
        vector<string> currPath;
        for(int j=0;j<colors.size();j++)
        {
            
            nodecolors[i]=colors[j];
            for(int k=0;k<v;k++)
            {
                if(adjacencyMatrix[i][k] && nodecolors[i]==nodecolors[k])
                {
                    nodecolors[i]="none";
                    break;
                }
            }
            if( nodecolors[i]!="none")
            {
                currPath.push_back(nodecolors[i]);
            }
            if(currPath.size()==v)
            {
                for(int a=0;i<v;i++)
                {
                    solution.push_back(currPath[a]);
                }

            }
        }
    }
    for(int i=0;i<nodecolors.size();i++)
    {
        cout<<nodecolors[i]<<" ";
    }
    cout<<endl;
}
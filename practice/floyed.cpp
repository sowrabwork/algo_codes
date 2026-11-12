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
    vector<vector<int>> adjecencymatrix(v,vector<int>(v,INT_MAX));
    for(int i=0;i<e;i++)
    adjecencymatrix[edges[i].st][edges[i].end]=edges[i].weight;
    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
        {
            for(int k=0;k<v;k++)
            {
                if(adjecencymatrix[j][k]>(double)adjecencymatrix[j][i]+adjecencymatrix[i][k]
                && adjecencymatrix[j][i]!=INT_MAX &&  adjecencymatrix[i][k]!=INT_MAX)
                adjecencymatrix[j][k]=adjecencymatrix[j][i]+adjecencymatrix[i][k];
            }
        }
    }
    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
        {
            if(i==j)
            cout<<"0 ";
            else if(adjecencymatrix[i][j]==INT_MAX)
            cout<<"∞"<<" ";
            else 
            cout<<adjecencymatrix[i][j]<<" ";
        }
        cout<<endl;
    }
}
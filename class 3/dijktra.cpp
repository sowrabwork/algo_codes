#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct edge{
    int st,end,val;
    edge(int st,int end,int val)
    {
        this->st=st;
        this->end=end;
        this->val=val;
    }
};


int main()
{
    int v,e;
    cout<<"enter the number of vertex and edges : ";
    cin>>v>>e;
    cout<<"enter 1 for derected graph and 0 for underected graph: ";
    int derectedCheck;
    cin>>derectedCheck;
    cout<<"enter the edges: "<<endl;
    vector<edge> edges;
    for(int i=0;i<e;i++)
    {
        int st,end,val;
        cin>>st>>end>>val;
        edges.push_back(edge(st,end,val));
    }
    if(!derectedCheck)
    {
        for(int i=0;i<e;i++)
        {
            edges.push_back(edge(edges[i].end,edges[i].st,edges[i].val));
        }
        e*=2;
    }
    int current_value[v];
    vector <bool>visited(v,false);
    fill(current_value,current_value+v,1000000);
    visited[0]=true;
    current_value[0]=0;
    int i=0;
    for(int k=0;k<v;k++)
    {
        for(int j=0;j<e;j++)
        {
            if(edges[j].st==i)
            {
                if(edges[j].val+current_value[i]<current_value[edges[j].end] && !visited[edges[j].end])
                {
                    current_value[edges[j].end]=edges[j].val+current_value[i];
                    
                }
            }
        }
        int mn=10000000;
        int now_at=-1;
        for(int i=0;i<v;i++)
        {
            if(current_value[i]<mn && !visited[i])
            {
                mn=current_value[i];
                now_at=i;
                
            }
        }
        if(now_at==-1)
        break;
        visited[now_at]=true;
        i=now_at;

    }
    cout<<"COST TO GO TO THE OTHER VARTICES:"<<endl;
    for(int i=0;i<v;i++)
    {
        cout<<i<<" : "<<current_value[i]<<endl;
    }
}

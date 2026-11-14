#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct pnt
{
    int x;
    int y;
};
pnt pivot;
int cross(pnt p,pnt c,pnt n)
{
    return (p.x-c.x)*(c.y-n.y)-(p.y-c.y)*(c.x-n.x);
}
bool sortlogic(pnt a,pnt b)
{
    int c=cross(pivot,a,b);//special
    if(c==0)
    return (a.x-pivot.x)*(a.x-pivot.x)+(a.y-pivot.y)*(a.y-pivot.y)<
           (b.x-pivot.x)*(b.x-pivot.x)+(b.y-pivot.y)*(b.y-pivot.y);
    return c>0;
}
int main()
{
    int n;
    cin>>n;
    vector<pnt> pnts(n);
    for(int i=0;i<n;i++)
    cin>>pnts[i].x>>pnts[i].y;
    int lowpointdex=0;
    for(int i=1;i<n;i++)
    if(pnts[i].y<pnts[lowpointdex].y)
    lowpointdex=i;
    else if(pnts[i].y==pnts[lowpointdex].y && pnts[i].x<pnts[lowpointdex].x)
    lowpointdex=i;
    swap(pnts[0],pnts[lowpointdex]);
    pivot=pnts[0];
    sort(pnts.begin()+1,pnts.end(),sortlogic);
    vector<pnt> stk;
    stk.push_back(pnts[0]);
    stk.push_back(pnts[1]);
    for(int next=2;next<n;next++)
    {
        while(stk.size()>=2 && cross(stk[stk.size()-2],stk[stk.size()-1],pnts[next])<=0)
        {
            stk.pop_back();
        }
        stk.push_back(pnts[next]);
    }
    for(pnt p:stk)
    cout<<p.x<<" "<<p.y<<endl;

}
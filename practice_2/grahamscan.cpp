#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct point
{
    int x;
    int y;
};

int cross(point a,point b,point c)
{
   return (a.x-b.x)*(b.y-c.y)-(a.y-b.y)*(b.x-c.x);
}
point pivot;
bool sortlogic(point a,point b)
{
    int ans=cross(pivot,a,b);
    if(ans==0)
    return (a.x-pivot.x)*(a.x-pivot.x)+(a.y-pivot.y)*(a.y-pivot.y)
    <(b.x-pivot.x)*(b.x-pivot.x)+(b.y-pivot.y)*(b.y-pivot.y);
    return ans>0;
}
int main()
{
    int n;
    cin>>n;
    vector<point> points(n);
    for(int i=0;i<n;i++)
    cin>>points[i].x>>points[i].y;
    int lowpointdex=0;
    for(int i=1;i<n;i++)
    {
        if(points[i].y<points[lowpointdex].y || (points[i].y == points[lowpointdex].y 
            && points[lowpointdex].x>points[i].x))
            lowpointdex=i; 
    }
    swap(points[0],points[lowpointdex]);
    pivot=points[0];
    sort(points.begin()+1,points.end(),sortlogic);
    vector<point> stk;
    stk.push_back(points[0]);
    stk.push_back(points[1]);
    for(int i=2;i<n;i++)
    {
        while( stk.size()>=2 && cross(stk[stk.size()-2],stk[stk.size()-1],points[i])<=0)
        {
            stk.pop_back();
        }
        stk.push_back(points[i]);
    }
    for(point pnt:stk)
    cout<<pnt.x<<" "<<pnt.y<<endl;

}
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct pnt
{
    int x;
    int y;
};
int main()
{
    int n;
    cin>>n;
    vector<pnt> pnts(n);
    for(int i=0;i<n;i++)
    cin>>pnts[i].x>>pnts[i].y;
    
}
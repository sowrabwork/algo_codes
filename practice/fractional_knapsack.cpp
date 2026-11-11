#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct item
{
    int weignt;
    int profit;
    int itemnumber;
};

bool sortlogic(item a,item b)
{
    return (double)a.profit/a.weignt>(double)b.profit/b.weignt;
}
int main()
{
    int n,capacity;
    cin>>n>>capacity;
    vector<item> items(n);
    for(int i=0;i<n;i++)
    items[i].itemnumber=i+1;
    for(int i=0;i<n;i++)
    cin>>items[i].weignt;
    for(int i=0;i<n;i++)
    cin>>items[i].profit;
    sort(items.begin(),items.end(),sortlogic);
    int currentweight=0;
    double profit=0;
    vector<int> itemnumbers;
    for(int i=0;i<n;i++)
    {
        if(currentweight+items[i].weignt>=capacity)
        {
            profit+=(double)items[i].profit/items[i].weignt*(capacity-currentweight);
            itemnumbers.push_back(items[i].itemnumber);
            break;
        }
        else
        {
            profit+=items[i].profit;
            itemnumbers.push_back(items[i].itemnumber);
            currentweight+=items[i].weignt;
        }
    }
    cout<<profit<<endl;
    for(int x:itemnumbers)
    cout<<x<<" ";
    cout<<endl;
    
}
#include<iostream>
#include<algorithm>
using namespace std;

struct item{
    int weight;
    int profit;
    double profitPerWeight;
};

bool sortLogic(item a,item b)
{
    if(a.profitPerWeight>b.profitPerWeight)
    return true;
    return false;
}

int main()
{
    int capacity;
    cout<<"enter the capacity: ";
    cin>>capacity;
    cout<<"enter the number of element: ";
    int n;
    cin>>n;
    item items[n];
    cout<<"enter the weight of the items:"<<endl;
    for(int i=0;i<n;i++)
    cin>>items[i].weight;
    cout<<"enter the profit of the items:"<<endl;
    for(int i=0;i<n;i++)
    cin>>items[i].profit;
    for(int i=0;i<n;i++)
    items[i].profitPerWeight=(double)items[i].profit/items[i].weight;
    sort(items,items+n,sortLogic);
    int currentweight=0;
    double profit=0;
    for(int i=0;i<n;i++)
    {
        if(currentweight+items[i].weight>=capacity)
        {
            profit+=items[i].profitPerWeight*(capacity-currentweight);
            break;
        }
        else
        {
            profit+=items[i].profit;
            currentweight+=items[i].weight;
        }
    }

    cout<<"profit : "<<profit<<endl;
}
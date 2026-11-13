#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> sizes(n);
    for(int i=0;i<n;i++)
    cin>>sizes[i];
    int ans=0;
    while(sizes.size()>1)
    {
        sort(sizes.begin(),sizes.end(),greater<int>());
        int a=sizes.back();
        sizes.pop_back();
        int b=sizes.back();
        sizes.pop_back();
        ans+=a+b;
        sizes.push_back(a+b);
    }
    cout<<ans<<endl;
}
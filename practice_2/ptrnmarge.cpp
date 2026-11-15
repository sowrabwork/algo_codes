#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> ptrs(n);
    for(int i=0;i<n;i++)
    cin>>ptrs[i];
    int ans=0;
    while(ptrs.size()>1)
    {
        sort(ptrs.begin(),ptrs.end(),greater<int>());
        int a=ptrs.back();
        ptrs.pop_back();
        int b=ptrs.back();
        ptrs.pop_back();
        ptrs.push_back(a+b);
        ans+=ptrs.back();
    }
    cout<<ans<<endl;
}
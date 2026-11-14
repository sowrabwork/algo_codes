#include<iostream>
#include<climits>
#include<vector>
using namespace std;
int main()
{
    string text,ptr;
    cin>>text>>ptr;
    long long int positionalval=1;
    long long int texthash=0;
    long long int ptrhash=0;

    for(long long int i=0;i<ptr.size();i++)
    {
        ptrhash+=positionalval*ptr[i];
        texthash+=text[i]*positionalval;
        positionalval*=10;
    }
    positionalval/=10;
    vector<long long int> ans;
    if(texthash==ptrhash && ptr==text.substr(0,ptr.size()))
    ans.push_back(0);
    for(long long int i=ptr.size();i<text.size();i++)
    {
        texthash=(texthash-text[i-ptr.size()])/10+text[i]*positionalval;
        if(texthash==ptrhash && ptr==text.substr(i-ptr.size()+1,ptr.size()))
        ans.push_back(i-ptr.size()+1);
    }
    for(long long int x:ans)
    cout<<x<<endl;
}
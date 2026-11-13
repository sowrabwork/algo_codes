#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
    string text,pattern;
    cin>>text>>pattern;
    long long positionalvalue=1;
    long long ptrhashvalue=0;
    long long texthashvalue=0;
    for(long long i=0;i<pattern.length();i++)
    {
        ptrhashvalue+=pattern[i]*positionalvalue;
        texthashvalue+=text[i]*positionalvalue;
        positionalvalue*=10;
    }
    positionalvalue/=10;
    vector<long long> foundex;
    if(texthashvalue==ptrhashvalue)
    {
        if(pattern==text.substr(0,pattern.size()))
        foundex.push_back(0);
    }
    for(long long i=1;i<text.length()-pattern.length()+1;i++)
    {
        texthashvalue=(texthashvalue-text[i-1])/10+text[i+pattern.length()-1]*positionalvalue;
        if(texthashvalue==ptrhashvalue && pattern==text.substr(i,pattern.size()))
        foundex.push_back(i);
    }
    for(long long x:foundex)
    cout<<x<<" ";
    cout<<endl;
    

}
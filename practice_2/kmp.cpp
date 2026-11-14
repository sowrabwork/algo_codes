#include<iostream>
#include<vector>
using namespace std;
int main()
{
    string str,ptr;
    cin>>str>>ptr;
    vector<int> lps(ptr.size());
    int i=0;
    int j=1;
    lps[0]=0;
    while(j<ptr.size())
    {
        if(ptr[i]==ptr[j])
        {
            lps[j]=i+1;
            i++;
            j++;
        }
        else if(i>0)
        {
            i=lps[i-1];
        }
        else
        {
            lps[j]=0;
            j++;
        }
    }
    i=0;
    j=0;
    vector<int> foundex;
    while(i<str.size())
    {
        if(str[i]==ptr[j])
        {
            i++;
            j++;
        }
        else if(j>0)
        {
            j=lps[j-1];
        }
        else
        {
            i++;
        }
        if(j==ptr.length())
        {
            foundex.push_back(i-j);
            j=lps[j-1];
        }
    }
    for(int x:foundex)
    cout<<x<<endl;

}
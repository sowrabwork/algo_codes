#include<iostream>
#include<vector>
using namespace std;
int main()
{
    string str,ptr;
    cin>>str>>ptr;
    int i=0;
    int j=1;
    vector<int> lps(ptr.size(),0);
    while(j<ptr.length())
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
            j++;
        }
    }
    vector<int> ans;
    int textptr=0;
    int patternptr=0;
    while(textptr<str.size())
    {
        if(str[textptr]==ptr[patternptr])
        {
            textptr++;
            patternptr++;
        }
        else if(patternptr>0)
        {
            patternptr=lps[patternptr-1];
        }
        else
        {
            textptr++;
        }
        if(patternptr==ptr.size())
        {
            ans.push_back(textptr-ptr.size());
            patternptr=lps[patternptr-1];
        }
    }
    if(ans.size()==0)
    cout<<"no match found"<<endl;
    else
    for(int x:ans)
    cout<<x<<" ";
    cout<<endl;
}
#include<iostream>
#include<vector>
using namespace std;
int main()
{
    cout<<"enter the text:"<<endl;
    string text;
    cin>>text;
    cout<<"enter the pattern:"<<endl;
    string pattern;
    cin>>pattern;
    vector<int> lps(pattern.length(),0);
    int i=0, j=1;
    while(j<pattern.length())
    {
        if(pattern[i]==pattern[j])
        {
            lps[j]+=lps[j-1]+1;
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
    int textPtr=0,patternPtr=0;
    int foundex=-1;
    while(textPtr<text.length())
    {
        if(text[textPtr]==pattern[patternPtr])
        {
            textPtr++;
            patternPtr++;
        }
        else if(patternPtr>0)
        {
            patternPtr=lps[patternPtr-1];
        }
        else
        {
            textPtr++;
        }
        if(patternPtr==pattern.length())
        {
            foundex=textPtr-pattern.length();
        }
    }
    if(foundex==-1)
    {
        cout<<"pattern not found"<<endl;
    }
    else
    {
        cout<<"foundex : "<<foundex<<endl;
    }
}
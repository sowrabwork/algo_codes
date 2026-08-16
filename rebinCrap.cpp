#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    cout<<"enter the text:"<<endl;
    string text;
    cin>>text;
    cout<<"enter the pattern: "<<endl;
    string pattern;
    cin>>pattern;
    long long int patternHash=0;
    long long int mod=1e9+7;
    long long positionValue=1;
    for(int i=0;i<pattern.length();i++)
    {
        patternHash=(patternHash+pattern[i]*positionValue)%mod;
        positionValue=(positionValue*256)%mod;
    }
    long long textHash=0;
    positionValue=1;
    for(int i=0;i<pattern.length();i++)
    {
        textHash=(textHash+text[i]*positionValue)%mod;
        positionValue=positionValue*256%mod;
    }
    int L=0,R=pattern.length();
    int foundex=-1;
    positionValue/=256;
    while(R<=text.length())
    {
        if(textHash==patternHash)
        {
            foundex=L;
            break;
        }
        else if(R==pattern.length())
        {
            break;
        }
        textHash=((textHash-text[L])/256+text[R]*positionValue)%mod;
        L++;
        R++;
    }
    if(foundex==-1)
    {
        cout<<"pattren not found"<<endl;
    }
    else
    {
        cout<<"pattren found at position : "<<foundex<<endl;
    }
}
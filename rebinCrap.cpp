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
    long long positionValue=(long long )pow(33,pattern.length()-1)%mod;
    for(int i=0;i<pattern.length();i++)
    {
        patternHash=(patternHash+pattern[i]*positionValue)%mod;
        positionValue=positionValue/33;
    }
    long long textHash=0;
    positionValue=positionValue=(long long )pow(33,pattern.length()-1)%mod;
    long long spositionValue=positionValue;
    for(int i=0;i<pattern.length();i++)
    {
        textHash=(textHash+text[i]*positionValue)%mod;
        positionValue=positionValue/33;
    }
    int L=0,R=pattern.length();
    int foundex=-1;
    while(R<=text.length())
    {
        if(textHash==patternHash)
        {
            foundex=L;
        }
        else if(R==text.length())
        {
            break;
        }
        if(foundex!=-1)
        {
            
            for(int i=0;i<pattern.length();i++)
            {
                if(pattern[i]!=text[L+i])
                {
                    foundex=-1;
                    break;
                }
            }
            if(foundex!=-1)
            {
                cout<<"foundex : "<<foundex<<endl;
            }
        }
        if(R!=text.length())
        textHash=((textHash-text[L]*spositionValue+mod)*33+text[R])%mod;
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
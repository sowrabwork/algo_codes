#include<iostream>
using namespace std;

int dp[1000][1000];
int lps(string text,int i,int j)
{
    if(i>j)
    return 0;
    if(i==j)
    return 1;
    if(dp[i][j]!=-1)
    return dp[i][j];
    int ans1=lps(text,i+1,j);
    int ans2=lps(text,i,j-1);
    int ans3=lps(text,i+1,j-1);
    if(text[i]==text[j])
    ans3+=2;
    return dp[i][j]=max(max(ans1,ans2),ans3);
}


int main()
{
    fill(&dp[0][0],&dp[0][0]+1000*1000,-1);
    string text;
    cin>>text;
    cout<<"LPS : "<<lps(text,0,text.length()-1)<<endl;
}
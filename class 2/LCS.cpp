#include<iostream>
using namespace std;
int dp[1000][1000];
int lps(string text1,string text2,int i,int j)
{
    if(i<0 || j<0)
    return 0;
    if(dp[i][j]!=-1)
    return dp[i][j];
    int ans1=lps(text1,text2,i-1,j);
    int ans2=lps(text1,text2,i,j-1);
    int ans3=lps(text1,text2,i-1,j-1)+(text1[i]==text2[j]);
    return dp[i][j]=max(max(ans1,ans2),ans3);
}


int main()
{
    fill(&dp[0][0],&dp[0][0]+1000*1000,-1);
    string str1,str2;
    cin>>str1>>str2;
    cout<<"LCS array length : "<<lps(str1,str2,str1.length()-1,str2.length()-1);
} 
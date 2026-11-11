#include<iostream>
using namespace std;
int dp[1000][1000];
int func(string str1,string str2,int i,int j)
{
    if(i<0 || j<0)
    return 0;
    if(dp[i][j]!=-1)
    return dp[i][j];
    int ans1=func(str1,str2,i-1,j);
    int ans2=func(str1,str2,i,j-1);
    int ans3=func(str1,str2,i-1,j-1)+(str1[i]==str2[j]);
    return dp[i][j]=max(ans1,max(ans2,ans3));
}

int main()
{
    fill(&dp[0][0],&dp[0][0]+1000*1000,-1);
    string str1,str2;
    cin>>str1>>str2;
    cout<<"ans: "<<func(str1,str2,str1.size()-1,str2.size()-1)<<endl;
}
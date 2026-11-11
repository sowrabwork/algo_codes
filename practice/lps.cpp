#include<iostream>
using namespace std;
int dp[1000][1000];
int func(string str,int i,int j)
{
    if(i==j)
    return 1;
    if(i>j)
    return 0;
    if(dp[i][j]!=-1)
    return dp[i][j];
    int ans1=func(str,i,j-1);
    int ans2=func(str,i+1,j);
    int ans3=func(str,i+1,j-1);
    if(str[i]==str[j])
    ans3+=2;
    return dp[i][j]=max(ans1,max(ans2,ans3));
}
int main()
{
    fill(&dp[0][0],&dp[0][0]+1000*1000,-1);
    string str;
    cin>>str;
    cout<<"ans: "<<func(str,0,str.size()-1)<<endl;
}
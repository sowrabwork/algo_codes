#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct job
{
    int jobnumber;
    int deadline;
    int profit;
};
bool sortlogic( job a,job b)
{
    return a.profit>b.profit;
}
int main()
{
    int n;
    cin>>n;
    vector<job> jobs(n);
    for(int i=0;i<n;i++)
    cin>>jobs[i].jobnumber>>jobs[i].deadline>>jobs[i].profit;
    sort(jobs.begin(),jobs.end(),sortlogic);
    int maxtime=0;
    for(int i=0;i<n;i++)
    maxtime=max(maxtime,jobs[i].deadline);
    vector<bool> timeslot(maxtime+1,false);
    vector<int> ans;
    int profit=0;
    for(int i=0;i<n;i++)
    {
        for(int j=jobs[i].deadline;j>=1;j--)
        {
            if(!timeslot[j])
            {
                timeslot[j]=true;
                ans.push_back(jobs[i].jobnumber);
                profit+=jobs[i].profit;
                break;
            }
        }
    } 
    cout<<profit<<endl;
    for(int x:ans)
    cout<<x<<" ";
    cout<<endl;
}
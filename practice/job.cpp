#include<iostream>
#include<algorithm>
#include<climits>
#include<vector>
using namespace std;
struct job
{
    int profit;
    int deadline;
    int jobnumber;
};
bool sortlogic(job a,job b)
{
    return a.profit>b.profit;
}
int main()
{
    int n;
    cin>>n;
    vector<job> jobs(n);
    for(int i=0;i<n;i++)
    cin>>jobs[i].jobnumber>>jobs[i].profit>>jobs[i].deadline;
    sort(jobs.begin(),jobs.end(),sortlogic);
    int maxdeadline=INT_MIN;
    for(int i=0;i<n;i++)
    if(jobs[i].deadline>maxdeadline)
    maxdeadline=jobs[i].deadline;
    int totalprofit=0;
    vector<int> jobdones;
    vector<bool> timeslot(maxdeadline+1,true);
    for(int i=0;i<n;i++)
    {
        for(int j=jobs[i].deadline;j>0;j--)
        if(timeslot[j])
        {
            totalprofit+=jobs[i].profit;
            jobdones.push_back(jobs[i].jobnumber);
            timeslot[j]=false;
            break;
        }
    }
    cout<<"profit: "<<totalprofit<<endl;
    for(int x:jobdones)
    cout<<x<<" ";
    cout<<endl;

}
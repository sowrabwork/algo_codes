#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;

map<string,int> profits;
map<string,int> deadlines;
bool compair(string a,string b)
{
    if(profits[a]>profits[b])
    return true;
    return false;
}

int main()
{
    cout<<"enter the number of jobs: ";
    int jobNum;
    cin>>jobNum;
    cout<<"enter the jobs:"<<endl;
    int maxdeadline=0;
    vector<string> sortedJobs;
    for(int i=0;i<jobNum;i++)
    {
        string jobName;
        int profit,deadline;
        cin>>jobName>>profit>>deadline;
        profits[jobName]=profit;
        deadlines[jobName]=deadline;
        if(deadline>maxdeadline)
        maxdeadline=deadline;
        sortedJobs.push_back(jobName);
    }
    sort(sortedJobs.begin(),sortedJobs.end(),compair);
    vector<bool> timeslot(maxdeadline+1,false);
    vector<string> performedJob;
    int totalprofit=0;
    for(int i=0;i<sortedJobs.size();i++)
    {
        for(int j=deadlines[sortedJobs[i]];j>=1;j--)
        {
            if(timeslot[j]==false)
            {
                timeslot[j]=true;
                performedJob.push_back(sortedJobs[i]);
                totalprofit+=profits[sortedJobs[i]];
                break;
            }
        }
    }
    cout<<"perfored jobs: ";
    for(int i=0;i<performedJob.size();i++)
    {
        cout<<performedJob[i]<<" ";
    }
    cout<<endl;
    cout<<"total profit: "<<totalprofit<<endl;

}
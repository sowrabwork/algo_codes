#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

int func(vector<vector<int>> &cost, vector<int> remaining, int cur)
{
    // no cities left: go back to the start
    if(remaining.empty())
        return cost[cur][0];

    int ans = INT_MAX;
    for(int i = 0; i < remaining.size(); i++)
    {
        int next = remaining[i];
        vector<int> remainingCopy = remaining;
        remainingCopy.erase(remainingCopy.begin() + i);

        int total = cost[cur][next] + func(cost, remainingCopy, next);
        ans = min(ans, total);
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(n));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> arr[i][j];

    vector<int> remaining;
    for(int i = 1; i < n; i++)
        remaining.push_back(i);

    cout << "min cost : " << func(arr, remaining, 0) << endl;
}
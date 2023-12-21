#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, target;
    cin >> n >> target;
    vector<int> denominations(n);
    for (int i = 0; i < n; i++)
    {
        cin >> denominations[i];
    }
    vector<long long int> dp(10e6, INT_MAX);
    dp[0] = 0;
    for (auto x : denominations)
    {
        for (int i = x; i <= target; i++)
        {
            dp[i] = min(dp[i], 1 + dp[i - x]);
        }
    }

    if (dp[target] == INT_MAX)
        cout << -1;
    else
        cout << dp[target];
}
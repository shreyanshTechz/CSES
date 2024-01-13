#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, limit;
    cin >> n >> limit;
    vector<int> weight(n);
    for (int i = 0; i < n; i++)
    {
        cin >> weight[i];
    }

    vector<pair<int, int>> dp(1 << n, {INT_MAX, INT_MAX});
    dp[0] = {1,0};
    for (int mask = 1; mask < (1 << n); mask++)
    {
        for (int i = 0; i < n; i++)
        {
            if ((1 << i) & mask)
            {
                int curr_space = dp[(1 << i) ^ mask].second;

                if (curr_space + weight[i] <= limit)
                {
                    dp[mask] = min(dp[mask], {dp[mask ^ (1 << i)].first, curr_space + weight[i]});
                }
                else
                {
                    dp[mask] = min(dp[mask], {1 + dp[mask ^ (1 << i)].first, weight[i]});
                }
            }
        }
    }
    cout << dp[(1<<n)-1].first;
}
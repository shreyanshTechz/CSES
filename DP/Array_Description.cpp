#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));

    // base case
    if (arr[0])
    {
        dp[0][arr[0]] = 1;
    }
    else
    {
        for (int x = 1; x <= m; x++)
        {
            dp[0][x] = 1;
        }
    }

    for (int i = 1; i < n; i++)
    {
        if (arr[i] == 0)
        {
            for (int k = 1; k <= m; k++)
            {
                dp[i][k] += (k + 1 <= m) ? dp[i - 1][k + 1] : 0;
                dp[i][k] %= mod;
                dp[i][k] += dp[i - 1][k];
                dp[i][k] %= mod;
                dp[i][k] += dp[i - 1][k - 1];
                dp[i][k] %= mod;
            }
        }
        else
        {
            dp[i][arr[i]] += (arr[i] + 1 <= m) ? dp[i - 1][arr[i] + 1] : 0;
            dp[i][arr[i]] %= mod;
            dp[i][arr[i]] += (arr[i] - 1 >= 0) ? dp[i - 1][arr[i] - 1] : 0;
            dp[i][arr[i]] %= mod;
            dp[i][arr[i]] += dp[i - 1][arr[i]];
            dp[i][arr[i]] %= mod;
        }
    }
    int ans = 0;
    for (int i = 1; i <= m; i++)
    {
        ans = (ans + dp[n - 1][i]) % mod;
        ans %= mod;
    }

    cout << ans;
}
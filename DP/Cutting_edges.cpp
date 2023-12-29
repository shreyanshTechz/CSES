#include <bits/stdc++.h>
using namespace std;


int main()
{
    int n, m;
    cin >> n >> m;

    if (n>m) swap(n,m);
    
    int dp[n + 1][m + 1];

    for (int i = 0; i <= min(n, m); i++)
    {
        dp[i][i] = 0;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= m; j++)
        {
            dp[i][j] = INT_MAX;

            for (int k = 1; k < j; k++)
            {
                dp[i][j] = min(dp[i][j], 1 + dp[i][j - k] + dp[i][k]);
            }

            for (int k = 1; k < i; k++)
            {
                dp[i][j] = min(dp[i][j], 1 + dp[i - k][j] + dp[k][j]);
            }

            if(j<=n and i<=m)
                dp[j][i] = dp[i][j];
        }
    }
    cout << dp[n][m];
}
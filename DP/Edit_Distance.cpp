#include <bits/stdc++.h>
using namespace std;
int main()
{
    string a, b;
    cin >> a >> b;

    int n = a.size(), m = b.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, INT_MAX));

    for (int i = 0; i <= m; i++)
    {
        dp[0][i] = i;
    }

    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = i;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            dp[i + 1][j + 1] = (a[i] == b[i]) ? dp[i][j] : min(1 + dp[i][i], dp[i + 1][j + 1]);
            dp[i + 1][j] = min(dp[i + 1][j], 1 + dp[i][j]);
            dp[i][j + 1] = min(dp[i][j + 1], 1 + dp[i][j]);
        }
    }

    cout << dp[n][m];
}
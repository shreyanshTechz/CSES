#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
int main()
{
    int n;
    cin >> n;
    vector<string> grid(n);
    for (int i = 0; i < n; i++)
    {
        cin >> grid[i];
    }
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    dp[0][0] = 1;

    if (grid[0][0] == '*')
    {
        cout << "0\n";
        return 0;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i >= 1 and grid[i][j] != '*')
                dp[i][j] = (dp[i][j] + dp[i - 1][j]) % mod;

            dp[i][j] %= mod;

            if (j >= 1 and grid[i][j] != '*')
                dp[i][j] = (dp[i][j] + dp[i][j - 1]) % mod;

            dp[i][j] %= mod;
        }
    }
    cout << dp[n - 1][n - 1];
}
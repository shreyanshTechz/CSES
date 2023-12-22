#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> pages(n), prices(n);
    for (int i = 0; i < n; i++)
    {
        cin >> prices[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> pages[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(x + 1));

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j <= x; j++)
        {
            if (j >= prices[i])
                dp[i][j] = max(dp[i + 1][j], dp[i + 1][j - prices[i]] + pages[i]);
            else
                dp[i][j] = dp[i + 1][j];
        }
    }

    cout << dp[0][x];


    // space optimization
    
    // vector<int> dp(x + 1);

    // for (int i = n - 1; i >= 0; i--)
    // {
    //     for (int j = x; j >=0; j--)
    //     {
    //         if (j >= prices[i])
    //             dp[j] = max(dp[j], dp[j - prices[i]] + pages[i]);
    //     }
    // }

    // cout << dp[x];

}
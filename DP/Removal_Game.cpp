#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    int n;
    cin >> n;
    vector<ll> arr(n), pre(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    pre[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        pre[i] = pre[i - 1] + arr[i];
    }

    int dp[n + 1][n + 1];

    for (int i = 0; i < n; i++)
    {
        dp[i][i] = arr[i];
    }

    dp[n][n] = 0;

    for (int i = 1; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            dp[i][j] = max(pre[j] - pre[i-1] - dp[i+1][j],pre[j] - pre[i-1] - dp[i][j-1]);
        }
    }

    cout<<dp[0][n-1];
}

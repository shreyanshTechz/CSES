#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    int n;
    cin >> n;
    vector<ll> arr(n+1), pre(n+1);
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    
    ll dp[n + 1][n + 1];
    for (int i = 1; i <= n; i++)
    {
        pre[i] = pre[i - 1] + arr[i];
        dp[i][i] = arr[i];
    }

    for (int j = 1; j < n; j++)
    {
        // k  = i+j;
        // i = k-j;
        for (int k = 1+j; k <= n+j; k++)
        {
            if(k > n) break;
            ll sums = pre[k] - pre[k-j-1];
            dp[k-j][k] = max(sums - dp[k-j+1][k],sums - dp[k-j][k-1]);
        }
        
    }

    cout<<dp[1][n];
}

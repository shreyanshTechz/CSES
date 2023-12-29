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
    
    int dp[n + 1][n + 1];
    for (int i = 1; i <= n; i++)
    {
        pre[i] = pre[i - 1] + arr[i];
        dp[i][i] = arr[i];
    }

    for (int j = 1; j < n; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            if(i+j > n) break;
            dp[i][j+i] = max(pre[j+i] - pre[i-1] - dp[i+1][j+i],pre[j+i] - pre[i-1] - dp[i][j+i-1]);
        }
        
    }

    cout<<dp[1][n];
}

#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int n, target;
    cin >> n >> target;
    vector<int> denominations(n);
    for (int i = 0; i < n; i++)
    {
        cin >> denominations[i];
    }
    vector<long long int> dp(10e6, 0);
    sort(denominations.begin(), denominations.end());
    dp[0]=1;
    for (auto x : denominations)
    {
        for (int i = 0; i <= target; i++)
        {
            if (i >= x)
                dp[i] = (dp[i] + dp[i - x]) % 1000000007;
        }
    }
    cout << dp[target];
}
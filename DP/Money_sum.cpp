#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    int sum = 0, mini = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
        mini = min(mini, arr[i]);
    }
    
    vector<int> dp(sum + 1);

    dp[0] = 1;
    for (auto x : arr)
    {
        for (int i = sum; i >= mini; i--)
        {
            if (i >= x)
                dp[i] |= dp[i - x];
        }
    }
    vector<int> ans;

    for (int i = mini; i <= sum; i++)
    {
        if (dp[i])
        {
            ans.push_back(i);
        }
    }
    cout << ans.size() << "\n";
    for (auto i : ans)
    {
        cout << i << " ";
    }
}
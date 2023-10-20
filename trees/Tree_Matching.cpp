#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> dp;
pair<int, int> func(int node, vector<vector<int>> &adj, int par = -1)
{
    vector<int> answer_including_node, answer_not_including_node;
    int sum = 0;
    if (dp[node].first)
        return dp[node];
    for (auto x : adj[node])
    {
        if (x == par)
            continue;
        pair<int, int> v = func(x, adj, node);
        sum += max(v.first, v.second);
        answer_including_node.push_back(v.first);
        answer_not_including_node.push_back(v.second);
    }
    int ans = sum;
    for (int i = 0; i < answer_including_node.size(); i++)
    {
        ans = max(ans, 1 + sum - answer_not_including_node[i] + answer_including_node[i]);
    }
    return dp[node] = {sum, ans};
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dp.assign(n + 1, {0, 0});
    cout << max(func(1, adj).first, func(1, adj).second);
}
#include <bits/stdc++.h>
using namespace std;

int dfs(int node, vector<vector<int>> &adj, vector<int> &sub)
{
    if (adj[node].size() == 0)
    {
        return 1;
    }
    for (auto x : adj[node])
    {
        sub[node] += dfs(x, adj, sub);
    }
    return sub[node] + 1;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    vector<int> sub(n + 1);
    for (int i = 2; i <= n; i++)
    {
        int x;
        cin >> x;
        adj[x].push_back(i);
    }
    dfs(1, adj, sub);
    for (int i = 1; i <= n; i++)
    {
        cout << sub[i] << " ";
    }
}
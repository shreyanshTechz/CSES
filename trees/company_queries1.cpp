#include <bits/stdc++.h>
using namespace std;
 
void dfs(int u, int p, vector<vector<int>> &dp, vector<vector<int>> &adj)
{
    dp[u][0] = p;
    int n = adj.size() - 1;
    // cout << u << " ";
    for (int i = 1; i <= log2(n); i++)
    {
        dp[u][i] = dp[dp[u][i - 1]][i - 1];
    }
    for (auto x : adj[u])
    {
        if (x != p)
        {
            dfs(x, u, dp, adj);
        }
    }
}
 
int main()
{
    int n, q;
    int u, v;
    cin >> n >> q;
    vector<int> par(n + 1);
    vector<vector<int>> adj(n + 1);
    for (int i = 2; i <= n; i++)
    {
        cin >> par[i];
        adj[par[i]].push_back(i);
    }
    vector<vector<int>> dp(n + 1, vector<int>(ceil(log2(n + 1))));
    // cout<<"p";
    dfs(1, 0, dp, adj);
 
    while (q--)
    {
        int x, k;
        cin >> x >> k;
        int d;
        while (x != -1 and k)
        {
            d = k & (~(k - 1));
            k = k & (k - 1);
            x = dp[x][log2(d)];
        }
        if (x != 0)
            cout << x << "\n";
        else
            cout << "-1\n";
    }
}
#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll start = 0, finish = -1;

void dfs(int node, vector<int> &vis, vector<vector<int>> &adj, vector<int> &par)
{
    vis[node] = 1;
    for (auto x : adj[node])
    {
        if (vis[x] == 0)
        {
            par[x] = node;
            dfs(x, vis, adj, par);
            if (start)
                return;
        }
        else if (vis[x] == 1)
        {
            start = x;
            finish = node;
            return;
        }
    }
    vis[node] = 2;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    vector<int> vis(n + 1);
    vector<int> par(n + 1);
    for (int i = 1; i <= n and !start; i++)
    {
        if (!vis[i])
        {
            dfs(i, vis, adj, par);
        }
    }

    if (!start)
    {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    vector<ll> ans;

    ans.push_back(start);

    for (auto x = finish; x != start; x = par[x])
    {
        ans.push_back(x);
    }
    ans.push_back(start);
    reverse(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for (auto x : ans)
        cout << x << " ";
}
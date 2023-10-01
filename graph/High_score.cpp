#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// standard Bellman ford Algorithm with little modification
// run a dfs call to check whether the node to be checked in last iteration comes in path from 1 to n

void dfs(int node, vector<vector<pair<ll, ll>>> &adj, vector<int> &vis)
{
    if (vis[node])
        return;
    vis[node] = 1;
    for (auto x : adj[node])
        dfs(x.first, adj, vis);
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pair<ll, ll>>> adj(n + 1), adj2(n + 1);
    while (m--)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, -1L * c});
        adj2[b].push_back({a, -1L * c});
    }
    vector<int> vis1(n + 1), vis2(n + 1);

    // run two dfs to check which nodes comes in path from 1->n
    dfs(1, adj, vis1);
    dfs(n, adj2, vis2);
    // node for which vis1[] = true and vis2[] = true comes in path of 1->n

    vector<ll> dist(n + 1, 1e18);
    dist[1] = 0;
    for (int i = 0; i < n; i++)
    {
        for (int u = 1; u <= n; u++)
        {
            for (auto x : adj[u])
            {
                int v = x.first;
                ll d = x.second;
                if (dist[u] != 1e18 and dist[u] + d < dist[v])
                {
                    dist[v] = d + dist[u];
                    if (i == n - 1 and vis1[v] and vis2[v]) // last iteration
                    {
                        cout << "-1\n"; // node v comes in the path of 1->n and n->1
                        return 0;
                    }
                }
            }
        }
    }
    cout << -1L * dist[n] << "\n";
}
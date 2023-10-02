#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 0x3f3f3f3f3f3f3f3f;
// standard bellman ford for negative cycle detection

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<ll>> edges;
    while (m--)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        edges.push_back({a, b, c});
    }
    vector<ll> dist(n + 1, INF);
    vector<ll> parent(n + 1);
    ll ptr = -1;
    for (int i = 0; i < n; i++)
    {
        ptr = 0;
        for (auto it : edges)
        {
            auto u = it[0], v = it[1], w = it[2];
            if (dist[u] != INT_MAX and dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                parent[v] = u;
                ptr = v;
            }
        }
    }
    if (!ptr)
    {
        cout << "NO\n";
        return 0;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            ptr = parent[ptr];
        }
        vector<ll> cycle;
        for (int v = ptr;; v = parent[v])
        {
            cycle.push_back(v);
            if (v == ptr and cycle.size() > 1)
            {
                break;
            }
        }
        reverse(cycle.begin(), cycle.end());

        cout << "YES\n";
        for (auto i : cycle)
            cout << i << " ";
    }
}
#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// standard Djaktra

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pair<ll, ll>>> adj(n + 1);
    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }
    vector<ll> dist(n + 1, LONG_LONG_MAX);
    vector<bool> vis(n + 1);
    dist[1] = 0;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q;
    q.push({0, 1});
    while (!q.empty())
    {
        auto f = q.top();
        int x = f.second;
        q.pop();
        if (vis[x])
            continue;
        vis[x] = true;
        for (auto j : adj[x])
        {
            if (dist[j.first] > j.second + dist[x])
            {
                dist[j.first] = j.second + dist[x];
                q.push({dist[j.first], j.first});
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << dist[i] << " ";
    }
}
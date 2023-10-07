#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ll n, m;
    cin >> n >> m;
    vector<vector<pair<ll, ll>>> adj(n + 1);
    while (m--)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }
    vector<ll> dist(n + 1, 1e18);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> p;
    dist[1] = 0;
    p.push({0, 1});
    vector<ll> vis(n + 1), ways(n + 1), minfl(n + 1), maxfl(n + 1);
    ways[1] = 1;
    while (!p.empty())
    {
        auto f = p.top();
        ll d = f.first;
        ll node = f.second;
        p.pop();
        if (vis[node])
            continue;
        vis[node] = 1;
        for (auto x : adj[node])
        {
            if (dist[x.first] >= x.second + dist[node])
            {
                if (dist[x.first] == x.second + dist[node])
                {
                    ways[x.first] = (ways[x.first] + ways[node]) % 1000000007;
                    minfl[x.first] = min(minfl[x.first], minfl[node] + 1);
                    maxfl[x.first] = max(maxfl[x.first], maxfl[node] + 1);
                }
                else
                {
                    dist[x.first] = x.second + dist[node];
                    ways[x.first] = ways[node] % 1000000007;
                    minfl[x.first] = minfl[node] + 1;
                    maxfl[x.first] = maxfl[node] + 1;
                }
                p.push({dist[x.first], x.first});
            }
        }
    }
    cout << dist[n] << " " << ways[n] << " " << minfl[n] << " " << maxfl[n] << " ";
}
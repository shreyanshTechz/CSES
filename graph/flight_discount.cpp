#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// two way dijaktra to get discounted smallest price
// good implementation

void dijaktra(vector<vector<pair<ll, ll>>> &adj, ll src, vector<ll> &dist, ll n)
{
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> p;
    dist[src] = 0;
    p.push({0, src});
    vector<ll> vis(n + 1);
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
            if (dist[x.first] > x.second + dist[node])
            {
                dist[x.first] = x.second + dist[node];
                p.push({dist[x.first], x.first});
            }
        }
    }
}

int main()
{
    ll n, m;
    cin >> n >> m;
    vector<vector<pair<ll, ll>>> adj1(n + 1), adj2(n + 1);
    while (m--)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        adj1[a].push_back({b, c});
        adj2[b].push_back({a, c});
    }
    vector<ll> dist1(n + 1, 1e18), dist2(n + 1, 1e18);
    dijaktra(adj1, 1, dist1, n);
    dijaktra(adj2, n, dist2, n);

    ll ans = 1e18;

    for (int i = 1; i <= n; i++)
    {
        for (auto x : adj1[i])
        {
            ans = min(ans, dist1[i] + dist2[x.first] + x.second / 2);
        }
    }

    cout << ans << "\n";
}

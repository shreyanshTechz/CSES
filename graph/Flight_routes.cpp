#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ll n, m, k;
    cin >> n >> m >> k;
    vector<vector<pair<ll, ll>>> adj(n + 1);
    while (m--)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }
    vector<ll> vis(n + 1);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> p;
    p.push({0, 1});
    ll count = 0;
    while (!p.empty())
    {
        auto f = p.top();
        p.pop();
        ll d = f.first;
        ll node = f.second;
        if (node == n and count < k)
        {
            cout << d << " ";
            count++;
        }

        vis[node]++;
        if (vis[node] <= k)
        {
            for (auto x : adj[node])
            {
                p.push({x.second + d, x.first});
            }
        }
    }
}
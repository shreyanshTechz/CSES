#include <bits/stdc++.h>
using namespace std;

void dfs(int root, vector<vector<int>> &adj, vector<int> &dist, int par)
{
    for (auto x : adj[root])
    {
        if (x == par)
            continue;
        dist[x] = 1 + dist[root];
        dfs(x, adj, dist, root);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    vector<int> dist1(n + 1, 0);
    vector<int> dist2(n + 1);
    n--;
    while (n--)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, adj, dist1, -1);
    int farthest = max_element(dist1.begin(), dist1.end()) - dist1.begin();
    // for(auto i:dist1) cout<<i<<" ";
    // cout<<"\n";
    dfs(farthest, adj, dist2, -1);
    // for(auto i:dist2) cout<<i<<" ";
    // cout<<"\n";
    cout << *max_element(dist2.begin(), dist2.end());
}
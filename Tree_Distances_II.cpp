#include <bits/stdc++.h>
using namespace std;
// We can solve this problem using in-out DP on trees.
void dfs(int root, vector<vector<int>> &adj, vector<int> &size, int par)
{
    for (auto x : adj[root])
    {
        if (x == par)
            continue;
        dfs(x, adj, size, root);
        size[root] += size[x];
        size[root]++;
    }
}

int main()
{
    int n;
    cin >> n;
    int m = n;
    vector<vector<int>> adj(n + 1);
    vector<int> size(n + 1);
    vector<int> dist(n+1);
    n--;
    while (n--)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1,adj,size,-1);
    dist = size;
    for(auto i:size) cout<<i<<" ";
}
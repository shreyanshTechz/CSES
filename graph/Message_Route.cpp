#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    while (m--)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<int> dist(n + 1, 1e9);
    vector<int> parent(n + 1);
    queue<int> q;
    q.push(1);
    dist[1] = 0;
    while (!q.empty())
    {
        auto f = q.front();
        q.pop();
        for (auto x : adj[f])
        {
            if (dist[x] > 1 + dist[f])
            {
                dist[x] = 1 + dist[f];
                parent[x] = f;
                q.push(x);
            }
        }
    }
    vector<int> path;
    if (parent[n] == 0)
    {
        cout << "IMPOSSIBLE";
    }
    else
    {
        int x = n;
        while(x!=1){
            path.push_back(x);
            x = parent[x];
        }
        path.push_back(1);
        cout<<path.size()<<"\n";
        for (int i = path.size() - 1; i >= 0; i--)
        {
            cout<<path[i]<<" ";
        }
        
    }
}
#include <bits/stdc++.h>
using namespace std;

// standard reverse dijaktra

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    vector<int> indegree(n + 1);
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        indegree[b]++;
    }

    indegree[0] = 1e9;

    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }
    vector<int> par(n + 1);
    vector<int> dist(n + 1, -1);
    dist[1] = 0;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (auto x : adj[node])
        {
            if (dist[node] != -1 and dist[x] < dist[node] + 1)
            {
                dist[x] = dist[node] + 1;
                par[x] = node;
            }
            indegree[x]--;
            if (indegree[x] == 0)
            {
                q.push(x);
            }
        }
    }
    // cout<<dist[n]<<" "<<INT_MIN<<" ";
    if (dist[n] == -1)
    {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    int d = dist[n] - dist[1];
    // cout<<d<<" ";
    vector<int> ans(d + 1);
    for (int i = d, u = n; i >= 0; i--)
    {
        ans[i] = u;
        u = par[u];
    }
    cout << d + 1 << "\n";
    for (auto i : ans)
        cout << i << " ";
}
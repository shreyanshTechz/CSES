#include <bits/stdc++.h>
using namespace std;

// find topological sort
// standard kahns algorithm

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    vector<int> indegree(n + 1);
    indegree[0] = 1e9;

    for (int i = 1; i <= n; i++)
    {
        for (auto x : adj[i])
        {
            indegree[x]++;
        }
    }

    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }
    vector<int> topo;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        topo.push_back(node);
        for (auto x : adj[node])
        {
            indegree[x]--;
            if (indegree[x] == 0)
            {
                q.push(x);
            }
        }
    }
    if (topo.size() != n)
    {
        cout << "IMPOSSIBLE\n";
    }
    else
    {
        for (auto i : topo)
            cout << i << " ";
    }
}
#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, int par, vector<vector<int>> &adj, vector<int> &vis, vector<int> &curr_path)
{
    vis[node] = 1;
    for (auto x : adj[node])
    {
        curr_path.push_back(x);
        if (!vis[x])
        {
            if (dfs(x, node, adj, vis, curr_path))
                return true;
        }
        else if (x != par)
            return 1;
        curr_path.pop_back();
    }

    return false;
}

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
        adj[b].push_back(a);
    }

    vector<int> curr_path;
    vector<int> vis(n + 1);

    for (int i = 1; i <= n; i++)
    {
        curr_path.push_back(i);

        if (!vis[i] and dfs(i, 0, adj, vis, curr_path))
        {
            vector<int> ans = {*curr_path.rbegin()};
            for (auto it = curr_path.rbegin() + 1; it != curr_path.rend(); it++)
            {
                ans.push_back(*it);
                if (*it == *curr_path.rbegin())
                    break;
            }
            cout << ans.size() << "\n";
            for (auto i : ans)
                cout << i << " ";
            return 0;
        }
        curr_path.pop_back();
    }
    cout << "IMPOSSIBLE";
}
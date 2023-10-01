#include <bits/stdc++.h>
using namespace std;
#define ll long long int
// standard floyd warshall algorithm

int main()
{
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<ll>> route(n + 1, vector<ll>(n + 1, 1e18));
    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        route[a][b] = min((ll)c, route[a][b]);
        route[b][a] = min((ll)c, route[a][b]);
    }
    for (int i = 1; i <= n; i++)
    {
        route[i][i] = 0;
    }
    for (int via = 1; via <= n; via++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                route[i][j] = min(route[i][j], route[i][via] + route[via][j]);
            }
        }
    }
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        if (route[x][y] != 1e18)
            cout << route[x][y] << "\n";
        else
            cout << "-1\n";
    }
}
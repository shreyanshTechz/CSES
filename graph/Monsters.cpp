#include <bits/stdc++.h>
using namespace std;

// fails only for one testcase when n==1000
// gives runtime error as we are building 1000*1000 vector
// correct solution is Monster2



int dir[4][2] = {{-1, 0}, {0, 1}, {0, -1}, {1, 0}};
char direction[4] = {'U', 'R', 'L', 'D'};

int main()
{
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }

    vector<vector<int>> dist(n, vector<int>(m, 1e9));
    queue<pair<int, int>> q;

    int sti = 0, stj = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (s[i][j] == 'A')
            {
                sti = i;
                stj = j;
            }
            if (s[i][j] == 'M')
            {
                q.push({i, j});
                dist[i][j] = 0;
            }
        }
    }

    while (!q.empty())
    {
        auto node = q.front();
        int x = node.first, y = node.second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dir[i][0], ny = y + dir[i][1];
            if (nx >= 0 and nx < n and ny >= 0 and ny < m and s[nx][ny] != '#')
            {
                if (dist[nx][ny] > 1 + dist[x][y])
                {
                    dist[nx][ny] = 1 + dist[x][y];
                    q.push({nx, ny});
                }
            }
        }
    }

    vector<vector<int>> vis(n, vector<int>(m, 1e9));
    vis[sti][stj] = 0;

    vector<vector<string>> ans(n, vector<string>(m, ""));

    q.push({sti, stj});

    while (!q.empty())
    {
        auto node = q.front();
        int x = node.first, y = node.second;
        q.pop();
        if (x == 0 or y == 0 or x == n - 1 or y == m - 1)
        {
            cout << "YES\n";
            cout << ans[x][y].size() << "\n";
            cout << ans[x][y];
            return 0;
        }
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dir[i][0], ny = y + dir[i][1];
            if (nx >= 0 and nx < n and ny >= 0 and ny < m and s[nx][ny] != '#')
            {
                if (vis[nx][ny] > 1 + vis[x][y] and 1 + vis[x][y] < dist[nx][ny])
                {
                    ans[nx][ny] = ans[x][y];
                    ans[nx][ny].push_back(direction[i]);
                    vis[nx][ny] = 1 + vis[x][y];
                    q.push({nx, ny});
                }
            }
        }
    }

    cout << "NO\n";
}
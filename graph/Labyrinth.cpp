#include <bits/stdc++.h>
using namespace std;

int vis[1000005] = {0};
int par[1000005];

int main()
{
    int n, m;
    cin >> n >> m;
    vector<string> mat(n);
    int stx, sty, enx, eny;
    for (int i = 0; i < n; i++)
    {
        cin >> mat[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == 'A')
            {
                stx = i;
                sty = j;
            }
            if (mat[i][j] == 'B')
            {
                enx = i;
                eny = j;
            }
        }
    }
    // bfs
    // dfs is giving wrong answer and also longest path
    // since n is 1000
    // we cannot take vis vector of 1000X1000 , so we took a par and vis of 10e5 with node value as m*x + y
    // we cannot take any other than m*x + y

    int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    // vector<int> vis(1e4);
    queue<int> q;
    q.push(stx * m + sty);
    while (!q.empty())
    {
        auto f = q.front();
        auto cordinates = f;
        int x = cordinates / m;
        int y = cordinates % m;
        vis[x * m + y] = 1;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dir[i][0], ny = y + dir[i][1];
            if (nx >= 0 and nx < n and ny >= 0 and ny < m and !vis[nx * m + ny] and (mat[nx][ny] == '.' or mat[nx][ny] == 'B'))
            {
                vis[nx * m + ny] = vis[f] + 1;
                par[nx * m + ny] = f;
                q.push(nx * m + ny);
            }
        }
    }

    if (!vis[enx * m + eny])
        cout << "NO";
    else
    {
        int st = stx * m + sty;
        vector<int> v;
        int i = enx * m + eny;
        while (i != st)
        {
            v.push_back(i);
            i = par[i];
        }
        cout << "YES\n";
        cout << v.size() << "\n";
        int x = st / m, y = st % m;
        string ans = "";
        for (int i = v.size() - 1; i >= 0; i--)
        {
            int x1 = v[i] / m, y1 = v[i] % m;
            if (x == x1)
                ans += (y > y1 ? 'L' : 'R');
            else
                ans += (x > x1 ? 'U' : 'D');
            x = x1, y = y1;
        }
        cout << ans << "\n";
    }
}
#include <bits/stdc++.h>
using namespace std;

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

    queue<pair<int, int>> q;
    vector<vector<int>> turn(n, vector<int>(m));
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
            }
        }
    }
    q.push({sti, stj});
    turn[sti][stj] = -1;
    while (!q.empty())
    {
        auto node = q.front();
        int x = node.first, y = node.second;
        q.pop();
        if (s[x][y] == 'A' and (x == 0 || x == n - 1 || y == 0 || y == m - 1))
        {
            int d = turn[x][y];
            string ans;
            // for(auto i:turn){ for(auto j:i) cout<<j<<" "; cout<<" \n";}

            while (d != -1)
            {
                // cout<<d<<" ";
                // cout<<x<<" "<<y<<" "<<"\n";

                ans += direction[d];
                x -= dir[d][0];
                y -= dir[d][1];

                d = turn[x][y];
            }
            reverse(ans.begin(), ans.end());
            cout << "YES\n";
            cout << ans.size() << "\n";
            cout << ans << "\n";
            return 0;
        }

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dir[i][0], ny = y + dir[i][1];
            if (nx >= 0 and nx < n and ny >= 0 and ny < m)
            {
                if (s[nx][ny] != '.')
                    continue;
                s[nx][ny] = s[x][y];
                if (s[x][y] == 'A')
                    turn[nx][ny] = i;
                q.push({nx, ny});
            }
        }
    }

    cout << "NO\n";
}
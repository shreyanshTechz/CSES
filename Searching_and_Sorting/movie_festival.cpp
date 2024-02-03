#include <bits/stdc++.h>
using namespace std;
#define int long long int
signed main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> movie;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        movie.push_back({x, y});
    }
    sort(movie.begin(), movie.end(), [](auto a, auto b)
         { return a.second < b.second; });
    int ans = 0, time = 0;
    for (int i = 0; i < n; i++)
    {
        if (time <= movie[i].first)
        {
            time = movie[i].second;
            ans++;
        }
    }
    cout << ans;
}
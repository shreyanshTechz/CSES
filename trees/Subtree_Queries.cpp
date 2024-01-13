#include <bits/stdc++.h>
using namespace std;
#define SZ 200005

int n, m, x, q, u, v;

int L[SZ];
vector<int> adj[SZ];
int jump[21][SZ];




int main()
{
    cin >> n >> q;
    for (int i = 2; i <= n; i++)
    {
        cin >> u;
        adj[u].push_back(i);
        adj[i].push_back(u);
    }
}
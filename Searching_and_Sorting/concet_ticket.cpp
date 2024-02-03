#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> tickets(n), customer(m);
    set<pair<int, int>> st;
    for (int i = 0; i < n; i++)
    {
        cin >> tickets[i];
        st.insert({tickets[i], i});
    }

    for (int i = 0; i < m; i++)
    {
        cin >> customer[i];
    }
    for (auto i : customer)
    {
        auto x = st.lower_bound({i+1, 0});
        if (x == st.begin())
        {
            cout << "-1\n";
        }
        else
        {
            x--;
            cout << (*x).first << "\n";
            st.erase(x);
        }
    }
    return 0;
}
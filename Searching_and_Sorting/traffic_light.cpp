#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int x,n,a;
    cin >> x >> n;
    set<int> s;
    s.insert(0);
    s.insert(x);
    set<int> ms;
    unordered_map<int,int> mp;
    mp[x] = 1;
    ms.insert(x);
    while(n--)
    {
        cin >> a;
        auto it = s.lower_bound(a);
        auto it2 = it;
        --it2;
        mp[*it - *it2]--;
        if (mp[*it - *it2]==0){
            ms.erase(ms.find(*it - *it2));
        }
        ms.insert(a - *it2);
        ms.insert(*it - a);
        mp[a-*it2]++;
        mp[*it-a]++;
        cout << *ms.rbegin() << " ";
        s.insert(a);
    }
}
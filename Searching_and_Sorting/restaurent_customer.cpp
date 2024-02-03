#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int ans = 1;
    map<int,int> mp;
    while (n--)
    {
        int a, b;
        cin >> a >> b;
        mp[a]++;
        mp[b]--;
    }
    int curr = 0;
    for(auto i:mp){
        curr = curr + i.second;
        ans = max(ans,curr);
    }
    cout<<ans;
    
}
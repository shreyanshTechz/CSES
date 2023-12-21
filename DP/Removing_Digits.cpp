#include<bits/stdc++.h>
using namespace std;

int maxdig(int x){
    int ans = x%10;
    while(x){
        x/=10;
        ans = max(ans,x%10);
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    int dp[n+1];
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = 1 + dp[i-maxdig(i)];
    }
    cout<<dp[n];
    
}
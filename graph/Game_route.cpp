#include<bits/stdc++.h>
using namespace std;
#define M 1000000007

int dfs(int x,int n,vector<vector<int>>& adj,vector<int>& vis,vector<int>& dp){
    if(x==n) return 1;
    if(dp[x]!=-1) return dp[x];
    vis[x] = 1;
    int ans= 0;
    for(auto node:adj[x]){
        if(!vis[node]) ans = (ans + dfs(node,n,adj,vis,dp)%M)%M;
    }
    vis[x] = 0;
    return dp[x] = ans;
}


int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n+1);
    while(m--){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
    }
    vector<int> vis(n+1);
    vector<int> dp(n+1,-1);
    cout<<dfs(1,n,adj,vis,dp)<<" ";

    
}
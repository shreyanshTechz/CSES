#include<bits/stdc++.h>
using namespace std;


bool dfs(int node,int par,vector<vector<int>>& adj,int team,vector<int>& vis){
    vis[node] = team;
    // cout<<node<<" ";
    bool ans = true;
    for(auto x:adj[node]){
        if(vis[x]==team) return false;
        if(vis[x]==!team) continue;
        if(x == par) continue;
        ans &= dfs(x,node,adj,!team,vis);
    }
    return ans;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n+1);
    while(m--){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> team(n+1,-1);
    for(int i=1;i<n+1;i++){
        if(team[i] == -1){
            if(dfs(i,-1,adj,0,team) == false){
                cout<<"IMPOSSIBLE";
                return 0;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout<<team[i]+1<<" ";
    }
    
}
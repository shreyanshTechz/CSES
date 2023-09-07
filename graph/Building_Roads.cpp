#include<bits/stdc++.h>
using namespace std;

// standard count number of component question

void dfs(int x,vector<vector<int>>& adj,vector<int>& vis,int n){
    vis[x] = 1;
    for(auto node:adj[x]){
        if(!vis[node]){
            dfs(node,adj,vis,n);
        }
    }
}


int main(){
    int n,m;
    cin>>n>>m;
    vector<int> vis(n+1);
    vector<int> ans;
    vector<vector<int>> adj(n+1);
    while(m--){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for (int i = 1; i <= n; i++)
    {
        if(!vis[i]){
            ans.push_back(i);
            dfs(i,adj,vis,n);
        }
    }
    if(ans.size())
    cout<<ans.size()-1<<"\n";
    else cout<<"0\n";

    for (int i = 0; i < ans.size()-1; i++)
    {
        cout<<ans[i]<<" "<<ans[i+1]<<"\n";
    }
    


   
    
     
}
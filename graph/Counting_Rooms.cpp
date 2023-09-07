#include<bits/stdc++.h>
using namespace std;

// standard flood fill algorithm

void dfs(int x,int y,vector<vector<int>>& vis,vector<string>& matrix,int n,int m){
    vis[x][y] = 1;
    int dir[4][2] = {{0,-1},{1,0},{-1,0},{0,1}};

    for (int i = 0; i < 4; i++)
    {
        int new_x =  x + dir[i][0];
        int new_y = y + dir[i][1];

        if(new_x>=0 and new_y>=0 and new_x<n and new_y<m and matrix[new_x][new_y]=='.' and !vis[new_x][new_y]){
            dfs(new_x,new_y,vis,matrix,n,m);
        }
    }
}


int main(){
    int n,m;
    cin>>n>>m;
    vector<string> matrix(n);
    for (int i = 0; i < n; i++)
    {
        cin>>matrix[i];   
    }
    int answer = 0;

    vector<vector<int>> vis(n,vector<int> (m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(!vis[i][j] and matrix[i][j] == '.')
            {
                dfs(i,j,vis,matrix,n,m);
                answer++;
                cout<<"\n";
            }
        }
        
    }
    
    cout<<answer;   
}
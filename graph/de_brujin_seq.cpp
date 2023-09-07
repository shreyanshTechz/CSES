#include<bits/stdc++.h>
using namespace std;

unordered_set<string> seen;
    vector<int> edges;
    void dfs(string node, int& k, string& A)
    {
        for (int i = 0; i < k; ++i) {
            string str = node + A[i];
            if (seen.find(str) == seen.end()) {
                seen.insert(str);
                dfs(str.substr(1), k, A);
                edges.push_back(i);
            }
        }
    }
    
    // Function to find a de Bruijn sequence
    // of order n on k characters
    string deBruijn(int n, int k, string A)
    {
    
        // Clearing global variables
        seen.clear();
        edges.clear();
    
        string startingNode = string(n - 1, A[0]);
        dfs(startingNode, k, A);
    
        string S;
    
        // Number of edges
        int l = pow(k, n);
        for (int i = 0; i < l; ++i)
            S += A[edges[i]];
        S += startingNode;
    
        return S;
    }
 

    string crackSafe(int n, int k) {
        string x;
        for(int i='0';i<'0'+k;i++){
            x.push_back(i);
        }
        // cout<<x;
        return deBruijn(n,k,x);
    }



int main(){
    int n;
    cin>>n;
    cout<<crackSafe(n,2);
}
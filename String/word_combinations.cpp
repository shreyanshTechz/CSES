#include <bits/stdc++.h>
using namespace std;
#define md 1000000007
struct TrieNode
{
    struct TrieNode *children[26];
    bool isEnd;
};

struct TrieNode* getNode()
{
    struct TrieNode *pNode = new TrieNode;
    pNode->isEnd = false;
    for (int i = 0; i < 26; i++)
    {
        pNode->children[i] = NULL;
    }
    return pNode;
}

void insert(struct TrieNode* root,string s)
{
    struct TrieNode* pNode = root;
    for (int i = 0; i < s.length(); i++)
    {
        if(!pNode->children[s[i]-'a']){
            pNode->children[s[i]-'a'] = getNode();
        }
        pNode = pNode->children[s[i]-'a'];
    }
    pNode->isEnd = true;
}
int search(struct TrieNode* root,string s,int x,vector<int>& dp)  
{
    struct TrieNode* pNode = root;
    int ans = 0;
    for (int i = x; i < s.length(); i++)
    {
        if(!pNode->children[s[i]-'a']){
            return ans;
        }
        pNode = pNode->children[s[i]-'a'];
        if(pNode->isEnd){
            (ans += dp[i+1])%=md;
        }
    }
    return ans;
}

int main()
{
    string mainstring;
    cin >> mainstring;
    int n;
    cin >> n;
    struct TrieNode* root = getNode();
    for (int i = 0; i < n; i++)
    {
        string p;
        cin>>p;
        insert(root,p);
    }
    int len = mainstring.size();
    vector<int> dp(len+1);
    dp[len] = 1;
    for (int i = len-1; i >= 0; i--)
    {
        dp[i] = search(root,mainstring,i,dp);
    }

    cout<<dp[0]; 
}
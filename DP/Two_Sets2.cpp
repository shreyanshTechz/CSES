#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
int main()
{
    int n;
    cin>>n;
    if(n%4!=0 and n%4!=3){
        cout<<"0\n";
        return 0;
    }
    int sum = (n*(n+1))/4;

    vector<int> dp(sum+1);

    dp[0] = 1;

    for (int i = 1; i < n; i++)
    {
        for (int j = sum; j > 0; j--)
        {
            if(j>=i)
            dp[j] = (dp[j] + dp[j-i])%mod;
        }
    }
    cout<<(dp[sum])%mod;
    

}
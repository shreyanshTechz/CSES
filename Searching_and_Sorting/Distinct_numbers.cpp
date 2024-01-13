#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int main(){
    ll n;
    cin>>n;
    map<ll,ll> s;
    while(n--){
        int x;
        cin>>x;
        if(!s[x]){
            s[x]=1;
        }
    }
    cout<<s.size();

}
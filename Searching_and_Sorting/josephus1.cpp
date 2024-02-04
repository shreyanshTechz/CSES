#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag,
		tree_order_statistics_node_update>
	pbds;

int main()
{

	int n,k;
    cin>>n>>k;
    pbds s;
    for (int i = 1; i <= n; i++)
    {
        s.insert(i);
    }
    int ind = k%n;
    while(n--)
    {
        auto p = s.find_by_order(ind);
        cout<<*p<<" ";
        s.erase(p);
        if(n) ind = (ind + k)%n;
    }
	return 0;
}

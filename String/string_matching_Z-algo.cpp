#include <bits/stdc++.h>
using namespace std;

int main()
{
    string text, pattern;
    cin >> text >> pattern;
    string x = pattern +'&'+ text;
    int n = x.length();
    int right = 0, left = 0;
    int z[n];
    for (int i = 1; i < n; i++)
    {
        if (i > right)
        {
            right = left = i;
            while (right < n and x[right] == x[right - left])
            {
                right++;
            }
            z[i] = right - left;
            right--;
        }
        else
        {
            int prev = i - left;
            if (z[prev] < right - i + 1)
            {
                z[i] = z[prev];
            }
            else
            {
                left = i;
                while (right < n and x[right] == x[right - left])
                {
                    right++;
                }
                z[i] = right - left;
                right--;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if(z[i] == pattern.size()) ans++;
    }
    cout<<ans;
    
}
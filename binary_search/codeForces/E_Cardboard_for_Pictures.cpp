// Question Link - https://codeforces.com/problemset/problem/1850/E

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    ll n, c;
    cin >> n >> c;
    vector<int> s(n);
    for (int i = 0; i < n; i++)
        cin >> s[i];

    ll l = 1;   ll r = 1e9;
    
    while (l <= r)
    {
        ll mid = l + (r - l) / 2;
        ll sum = 0;
        for (ll i = 0; i < n; i++)
        {
            sum += (s[i] + 2 * mid) * (s[i] + 2 * mid); 
            if (sum > c)
                break;
        }
        if (sum == c)
        {
            cout << mid << endl;
            return;
            // return;
        }

        if (sum < c)
            l = mid + 1;
        else
            r = mid - 1;
    }
}

int main()
{
    ll t;
    cin >> t;

    while (t--)
    {
        solve();
    }
}
// Question Link - https://codeforces.com/problemset/problem/1883/B

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    int n; int k;   cin>>n>>k;
    string s; cin>>s;
    unordered_map<char, int> mp;

    for(int i=0; i<n; i++) {
        mp[s[i]]++;
    }

    int even=0, odd=0;

    for(const auto &pair: mp) {
        if(pair.second%2==0)    even++;
        else odd++;
    }

    // cout<<"n: "<<n<<"   k: "<<k<<"  even: "<<even<<"  odd: "<<odd<<"    ";

    if(odd-k <= 1)   cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}



int main()
{
    int t;
    cin >> t;

    
    while(t--)
    {
        solve();
    }
}
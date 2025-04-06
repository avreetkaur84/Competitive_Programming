// Question Link - https://codeforces.com/contest/1666/problem/D

// what mattered was only t characters and their order, 

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;



void solve() {
    string s, t;    cin>>s>>t;
    unordered_map<char, int> mp;
    string res="";

    for(int i=0; i<t.length(); i++) {
        mp[t[i]]++;
    }

    for(int i=s.length()-1; i>=0; i--) {
        if(mp[s[i]]>0) {
            res = s[i]+res;
            mp[s[i]]--;
        }
    }
    
    if(res==t) cout<<"YES"<<endl;
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
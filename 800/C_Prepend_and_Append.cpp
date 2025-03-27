// Question Link - https://codeforces.com/problemset/problem/1791/C

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    int n; cin>>n;
    string s; cin>>s;

    int i=0, j=n-1;
    while(i<j && s[i]!=s[j]) {
        i++; j--;
    }

    cout<<j-i+1<<endl;  return;
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
// Question Link - https://codeforces.com/problemset/problem/1606/A

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

// how come logic of this question is so simple!!

void solve() {
    string s;   cin>>s;
    int ab=0, ba=0;
    int n = s.length();

    if(s[0]==s[n-1])  {
        cout<<s<<endl;  return;
    } else {
        s[0]=s[n-1];
        cout<<s<<endl;  return;
    }

    // cout<<s<<endl;
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
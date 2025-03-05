// Question Link - 

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    string s;   cin>>s;

    int n = s.length();

    // for(int i=n-2; i>=0; i--) {
    //     if(s[i]==s[i+1]) {
    //         s[i] = s[i-1];
    //         s.pop_back();
    //     }
    // }

    // simple observe
    for(int i=0; i<n-1; i++) {
        if(s[i]==s[i+1]) {
            cout<<1<<endl;
            return;
        }
    }

    cout<<s.length()<<endl;
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
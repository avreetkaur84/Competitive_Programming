// Question Link - 

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin>>n;
    string s; cin>>s;
    // int cnt=0, i=n-2, j=n-1;
    int cnt=0, i=1;
    
    
    if(s[0]=='1')   cnt++;

    // find 1 appearing after zero
    while(i<n) {
        if(s[i-1]!=s[i]) {
            cnt++;
        }
        i++;
    }

    // while(i>=0) {
    //     if(s[i]=='1' && s[j]=='0') {
    //         cnt+=2;
    //         // cout<<cnt<<endl;
    //         i-=2; j-=2;
    //     } else if (s[i]=='0' && s[j]=='1') {
    //         cnt++; j--; i--;
    //     }
    //     i--; j--;

    // }

    cout<<cnt<<endl;
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
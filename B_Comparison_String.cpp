// Question Link - 

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    int n; cin>>n;
    string s; cin>>s;
    int maxx=0, cnt=1;

    for(int i=1; i<n; i++) {
        if(s[i]==s[i+1]) {
            if(i==n-1) cnt+=2;
            else cnt++;
        }
        else {
            cout<<i<<"  ";
            maxx=max(maxx, cnt);
            cnt=1;
        }
    }
    maxx=max(maxx, cnt);

    cout<<maxx+1<<endl;
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
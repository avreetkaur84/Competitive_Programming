// Question Link - 

#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    int n;  cin>>n;
    string s;   cin>>s;
    ll cnt=0;

    for(int i=0; i<n; i++) {
        string s1 = s;
        s1[i] = (s[i]=='0') ? '1' : 0;
        for(int j=0; j<n; j++) {
            if(s1[j]=='1')   cnt++;
        }
    }

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
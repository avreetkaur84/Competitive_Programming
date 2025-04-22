// Question Link - https://codeforces.com/contest/2103/problem/B

// I was so close to solution in the contest :(

#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    ll n;   cin>>n;
    string s;   cin>>s;
    ll cnt=0; 

    for(int i=0; i<n; i++) {
        if(i>0 && (s[i-1]!=s[i])) {
            cnt++;  
        }
    }

    // cout<<"cnt: "<<cnt<<"   ";
    if(s[0]=='1')   cnt++;

    if(cnt>=3)  cout<<n+cnt-2<<endl;
    else if(cnt==2) cout<<n+cnt-1<<endl;
    else    cout<<n+cnt<<endl;
    

    
    // if(flag==false) {
    //     if(s[0]=='0')   cout<<n+cnt<<endl;
    //     else cout<<n+1<<endl;
    // }  
    // else if(cnt==1) {
    //     cout<<n+cnt<<endl;
    // }
    // else cout<<n+cnt-1<<endl;
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
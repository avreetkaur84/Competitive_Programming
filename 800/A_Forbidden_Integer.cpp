// Question Link - https://codeforces.com/problemset/problem/1845/A

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    int n, k, x;
    cin>>n>>k>>x;

    if(x!=1) {
        cout<<"YES"<<endl;
        cout<<n<<endl;
        while(n--)  cout<<1<<" ";
    } else if (k==1 || (n%2!=0 && k==2)) {
        cout<<"NO";
    } else {
        if(n%2==0) {
            cout<<"YES"<<endl; n/=2;
            cout<<n<<endl;
            while(n--)  cout<<2<<" ";
        } else {
            int ans = (n/2)-1;
            cout<<"YES"<<endl;
            cout<<ans+1<<endl;
            while(ans--)  cout<<2<<" ";
            cout<<3;
        }
    }

    cout<<endl;
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
// Question Link - 

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m; cin>>n>>m;
    vector<int> a(n); int b;

    for(int i=0; i<n; i++)  cin>>a[i];
    cin>>b;    // for m

    for(int i=1; i<n; i++) {
        if(a[i-1]>a[i]) {
            // a[i-1] = b-a[i-1];

            // if(a[i-1]<a[i-2] && i>1) {
            //     cout<<"NO"<<endl; return;
            // } else if(a[i-1]>a[i]) {
            //     cout<<"NO"<<endl; return;
            // }

            if(b-a[i-1]>a[i]) {
                cout<<"NO"<<endl; return;
            }
            
            a[i-1] = b-a[i-1];
        } 
    }

    if(is_sorted(a.begin(), a.end()))   cout<<"YES"<<endl;
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
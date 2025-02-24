// Question Link - https://codeforces.com/problemset/problem/1859/A

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin>>n;
    vector<int> a(n);
    vector<int> b;  vector<int> c;
    map<int, int> fq;
    for(int i=0; i<n; i++) {
        cin>>a[i];
        fq[a[i]]++;

        // if(a[i]%2==0)   b.push_back(a[i]);
        // else c.push_back(a[i]);
    }

    if(fq.size()==1) {
        cout<<-1<<endl;
        return;
    }

    int max = *max_element(a.begin(), a.end());

    for(int i=0; i<n; i++) {
        if(a[i]==max)   c.push_back(a[i]);
        else b.push_back(a[i]);
    }

    cout<<b.size()<<" "<<c.size()<<endl;
    for(int &x : b) cout<<x<<" ";
    cout<<endl;

    for(int &x : c) cout<<x<<" ";
    cout<<endl;

    // length of b & c
    // output elements of b & c.
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
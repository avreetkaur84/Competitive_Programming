#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin>>t;

    for(int x=t; x>0; x--) {
        
        int n; cin>>n;
        vector<int> a(n); vector<int> b(n);
        unordered_set<int> as; unordered_set<int> bs;
        // cout<<"Enter";

        for(int i=0; i<n; i++) {
            cin>>a[i];
            as.insert(a[i]);
            // cout<<"Enter";
        }

        for(int i=0; i<n; i++) {
            cin>>b[i];
            bs.insert(b[i]);
            // cout<<"Enter";
        }

        // MY APPROACH
        // if(as.size()<2 && bs.size()<2)  cout<<"NO"<<endl;
        // else if((as.size()==2 && bs.size()==1) || (bs.size()==2 && as.size()==1))   cout<<"NO"<<endl;
        // else if((as == bs) && (as.size()==1 && bs.size()==1))   cout<<"NO"<<endl;

        // OPTIMAL APPROACH
        if((as.size()+bs.size())<4) cout<<"NO"<<endl;
        
        else cout<<"YES"<<endl;
    }
}
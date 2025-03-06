// Question Link - 

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    int n; cin>>n;
    string s; cin>>s;
    int cnt=0, t_cnt=0, dot=0;

    for(char ch : s) {
        if(ch=='.') {
            t_cnt++;    dot++;
            if(t_cnt==3) {
                cout<<2<<endl;  return;
            }
        } else {  
            // cout<<"t_cnt: "<<t_cnt<<"  ";
            if(t_cnt==3) {
                cout<<2<<endl;  return;
            }
            t_cnt=0;
        }
    }

    cout<<dot<<endl;
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
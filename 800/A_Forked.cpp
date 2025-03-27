// Question Link - https://codeforces.com/problemset/problem/1904/A

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    int a, b; cin>>a>>b;
    int xk, yk; cin>>xk>>yk;
    int xq, yq; cin>>xq>>yq;

    // vector<vector<int>> arr(8, vector<int> (2));
    vector<vector<int>> arr = {{a,b}, {-a, b}, {a, -b}, {-a, -b}, {b,a}, {-b, a}, {b, -a}, {-b, -a}};

    set<pair<int, int>> k;
    set<pair<int, int>> q;

    for(int i=0; i<arr.size(); i++) {
        k.insert({xk+arr[i][0], yk+arr[i][1]});
        q.insert({xq+arr[i][0], yq+arr[i][1]});
    }

    int cnt=0;
    for(auto &pos : k) {
        if(q.count(pos))    cnt++;
    }

    cout<<cnt<<endl;

    // int x_diff = abs(xk-xq);
    // int y_diff = abs(yk-yq);

    // if((x_diff+y_diff)<(a+b)) {
    //     cout<<0<<endl;  return;
    // }

    // if((xk==xq || yk==yq) || (xk==xq && yk==yq)) {
    //     cout<<2<<endl; return;
    // }

    // if((x_diff>a && x_diff>b) && (y_diff>a && y_diff>b)) {
    //     cout<<1<<endl; return;
    // }
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
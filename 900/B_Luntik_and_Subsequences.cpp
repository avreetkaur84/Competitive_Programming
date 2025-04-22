// Question Link - 

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int fact(int n) {
    if(n==0) return 1;

    return n*fact(n-1);
}

void solve() {
    int n;   cin>>n;
    vector<int> arr(n);
    int z_cnt=0, o_cnt=0;
    ll res=0;

    for(int i=0; i<n; i++) {
        cin>>arr[i];
        if(arr[i]==0)   z_cnt++;
        else if(arr[i]==1)  o_cnt++;
    }

    // res = o_cnt + (z_cnt*o_cnt) + fact(z_cnt) -1;
    // cout<<"fact of "<<z_cnt<<":  "<<fact<<"  ";

    res = o_cnt * (pow(2, z_cnt));

    cout<<res<<endl;
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
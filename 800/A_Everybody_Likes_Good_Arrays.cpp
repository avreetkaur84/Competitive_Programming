// Question Link - 

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    int n=0; cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin>>arr[i];

    int i=n-1, cnt=0;
    while(i>0) {
        if((arr[i]%2==0 && arr[i-1]%2==0) || (arr[i]%2!=0 && arr[i-1]%2!=0)) {
            int pro = arr[i]*arr[i-1];
            arr.pop_back();
            arr.pop_back();
            arr.push_back(pro);
            cnt++;
        }
        i--;
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
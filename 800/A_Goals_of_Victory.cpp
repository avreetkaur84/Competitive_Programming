// Question Link - https://codeforces.com/problemset/problem/1877/A

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;  cin>>n;
    vector<int> arr(n-1);
    int sum=0;
    for(int i=0; i<arr.size(); i++) {
        cin>>arr[i];
        sum+=arr[i];
    }

    cout<<-sum<<endl;
    
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
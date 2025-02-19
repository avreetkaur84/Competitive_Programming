// Question Link - https://codeforces.com/contest/2069/problem/A

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// OPTIMAL APPROACH
void solve() {
    int n; cin>>n;
    vector<int> arr(n-2);
    for(int &x : arr)   cin>>x;

    if(arr.size()==1) {
        cout<<"YES"<<endl;
        return;
    }

    for(int i=1; i<arr.size()-1; i++) {
        if(arr[i-1]==1 && arr[i]==0 && arr[i+1]==1) {
            cout<<"NO"<<endl; 
            return;
        }
    }

    cout<<"YES"<<endl;
}

// My first approach
// void solve() {
//     int n; cin>>n;
//     vector<int> arr(n-2);
//     for(int &x : arr)   cin>>x;

//     if(arr.size()==1) {
//         cout<<"YES"<<endl;
//         return;
//     }
    
//     int i=arr.size()-1;
//     bool flag = true;
//     bool slap = true;

//     while(i--) {
//         if(arr[i]!=1 && flag==true) {
//             flag = false;
//             // cout<<"i: "<<i<<endl;
//         }

//         if(!flag && (arr[i]==1 && arr[i-1]==0) && i>1) {
//             slap = false;
//             // cout<<"i: "<<i<<endl;
//         }

//         if(!slap && arr[i]==1) {
//             cout<<"NO"<<endl;
//             return;
//         }
//     }
//     cout<<"YES"<<endl;
// }




int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        solve();
    }
}
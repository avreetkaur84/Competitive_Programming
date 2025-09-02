// Question Link - https://codeforces.com/contest/1352/problem/D

#include <bits/stdc++.h>
#define ll long long
using namespace std;

/*
    alice -> even -> factor: a_prev
    bob -> odd -> factor: b_prev
*/

void solve() {
    ll n;  cin>>n;
    vector<int> arr(n); 
    for(int i=0; i<n; i++) cin>>arr[i];

    ll i=0, j=n-1, a_prev=0, b_prev=0, a_cnt=0, b_cnt=0, moves=0;

    // cout<<"i j ap bp m ac bc\n";
    // cout<<i<<" "<<j<<" "<<a_prev<<" "<<b_prev<<" "<<moves<<" "<<a_cnt<<" "<<b_cnt<<endl;

    while(i<=j) {
        if(moves&1) {
            b_prev=0;
            while(a_prev>=0) {
                b_prev+=arr[j]; a_prev-=arr[j]; b_cnt+=arr[j]; j--;
                // cout<<"a_prev: "<<a_prev<<" j: "<<j<<endl;
                if(i>j) break;
            }
        } else {
            a_prev=0;
            while(b_prev>=0) {
                a_prev+=arr[i]; b_prev-=arr[i]; a_cnt+=arr[i]; i++;
                if(i>j) break;
            }
        }
        moves++;
        // cout<<i<<" "<<j<<" "<<a_prev<<" "<<b_prev<<" "<<moves<<" "<<a_cnt<<" "<<b_cnt<<endl;
    }

    // cout<<i<<" "<<j<<" "<<a_prev<<" "<<b_prev<<" "<<moves<<" "<<a_cnt<<" "<<b_cnt<<endl;
    cout<<moves<<" "<<a_cnt<<" "<<b_cnt<<endl;
    // cout<<endl;
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
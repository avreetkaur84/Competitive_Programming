// Question Link - 

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    int n;  cin>>n;
    vector<int> arr(n);

    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }

    ll cnt=0;

    for(int i=n-2; i>=0; i--) {
        // cout<<"i: "<<i<<"   arr[i]: "<<arr[i]<<"  arr[i+1]: "<<arr[i+1]<<endl;
        while(arr[i]>=arr[i+1] && arr[i]>0) {
            arr[i] = arr[i]/2;
            cnt++;
        }
        
        if(arr[i]==arr[i+1]) {
            cout<<-1<<endl; return;
        }
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
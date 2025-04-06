// Question Link - 

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

// eliminaet the 1 -> eliminate the main problem!!!

void solve() {
    int n; cin>>n;
    vector<ll> arr(n);

    for(int i=0; i<n; i++)  {
        cin>>arr[i];
        arr[i]++;
    }

    // sort(arr.begin(), arr.end());

    // if(arr[0]==1) arr[0]++;
    for(int i=1; i<n; i++) {
        // if(arr[i-1]==1) arr[i-1]++;
        if(arr[i]%arr[i-1]==0) {
            arr[i]++;  
        }
    }

    for(int i=0; i<n; i++)  cout<<arr[i]<<" ";
    cout<<endl;
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
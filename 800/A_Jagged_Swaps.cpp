// Question Link - 

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin>>n;
    vector<int> arr(n);
    set<int> st;    
    for(int i=0; i<n; i++)  cin>>arr[i];

    st.insert(arr[0]);

    // if(is_sorted(arr.begin(), arr.end()))   cout<<"NO"<<endl;

    for(int i=1; i<n-1; i++) {
        if(arr[i]>n)    cout<<"NO"<<endl;

        if(st.find(arr[i]) != st.end()) cout<<"NO"<<endl;

        if(arr[i-1]<arr[i] || arr[i]>arr[i+1]) {
            int temp = arr[i];
            arr[i] = arr[i+1];
            arr[i+1] = arr[i];
        }
    }

    if(is_sorted(arr.begin(), arr.end()))   cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
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
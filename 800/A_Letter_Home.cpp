// Question Link - https://codeforces.com/contest/2121/problem/A

#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    int n, s;  cin>>n>>s;
    vector<int> arr(n);
    // int idx=0;

    for(int i=0; i<n; i++) {
        cin>>arr[i];
        // if(arr[i]==s || arr[i]<s) idx=i;
    }

    int c1=0, c2=0;
    if(arr[0]<s && arr[n-1]>s) {
        c1 = (s-arr[0])+(arr[n-1]-arr[0]);
        c2 = (arr[n-1]-s)+(arr[n-1]-arr[0]);
        cout<<min(c1, c2)<<endl; return;
    } else if(arr[0]>=s) {
        cout<<arr[n-1]-s<<endl; return;
    } else if(arr[n-1]<=s) {
        cout<<s-arr[0]<<endl; return;
    }
    
    // cout<<"c1: "<<c1<<" c2: "<<c2<<"    ";
    // cout<<cnt<<endl;
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
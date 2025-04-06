// Question Link - 

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    ll n, q;    cin>>n>>q;
    vector<int> arr(n); 
    vector<int> prefix(n);  vector<int> sufix(n);

    for(int i=0; i<n; i++) {
        cin>>arr[i];

        // prefix sum
        if(i==0)    prefix[0]=arr[i];
        else prefix[i] = prefix[i-1]+arr[i];
    }

    // suffix sum
    sufix[n-1]=arr[n-1];
    for(int i=n-2; i>=0; i--) {
        sufix[i] = sufix[i+1]+arr[i];
    }

    for(int i=0; i<q; i++) {
        ll l, r, k; cin>>l>>r>>k;
        ll sum=0;
        l--; r--;

        if(l-1>=0)   sum += prefix[l-1];
        sum += k*(r-l+1);

        if(r+1<n)   sum += sufix[r+1];

        if(sum%2!=0)    cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

}



int sumArr(int startIdx, int endIdx, vector<int> arr) {
    ll sum=0;
    for(int i=startIdx; i<endIdx; i++) {
        sum+=arr[i];
    }

    return sum;
}

void solve1() {
    ll n, q;    cin>>n>>q;
    vector<int> arr(n); 
    vector<bool> res(q, false);

    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }

    for(int i=0; i<q; i++) {
        ll l, r, k; cin>>l>>r>>k;
        ll sum=0;
        // res compute
        // sum till l-1
        sum += sumArr(0, l-1, arr );
        // cout<<i<<": "<<sum<<"   ";
        // sum -> l to r
        sum += (k*(r-l+1));
        // cout<<i<<": "<<sum<<"   ";
        // sum -> after r
        sum += sumArr(r, n, arr);

        // cout<<i<<": "<<sum<<endl;
        if(sum%2!=0)    res[i]=true;
    }


    for(int i=0; i<q; i++) {
        if(res[i])  cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

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
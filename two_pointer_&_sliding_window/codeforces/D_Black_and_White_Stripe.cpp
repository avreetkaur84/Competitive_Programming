// Question Link - https://codeforces.com/problemset/problem/1690/D

#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    int n, k;  cin>>n>>k;
    vector<char> arr(n);
    for(int i=0; i<n; i++) cin>>arr[i];
    int minn=0;

    for(int i=0; i<k; i++) {
        if(arr[i]=='W') minn++;
    }

    int i=1, j=k, cnt=minn;
    while(j<n) {
        if(arr[j]=='W') cnt++;
        if(arr[i-1]=='W') cnt--;
        minn=min(cnt, minn);
        i++; j++;
    }

    cout<<minn<<endl;
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
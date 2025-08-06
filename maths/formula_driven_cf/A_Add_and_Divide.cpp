// Question Link - https://codeforces.com/problemset/problem/1485/A

#include <bits/stdc++.h>
#define ll long long
using namespace std;

/*
For this maths question, I had no idea by how much amount I should increase b, as by incrementing the b, we can reduce the operations by half.
So, from editorial I got to know that, incrementing b till 30 is good, as our limi tis till 10^9, and we know by one operation we can reduce operations by half, by log n. 
So, we will crease b till 30 and will selct the minimum possible moves.
*/

ll cntR(int a, int b) {
    ll cnt=0;
    while(a>0) {
        a/=b;  cnt++;
    } 
    return cnt;
}

void solve() {
    ll a, b; cin>>a>>b;
    ll res=INT_MAX;
    
    int n=(b<=30) ? 30-b : 0; 
    for(int i=0; i<=n; i++) {
        ll cnt=i;  int y=b, x=a;
        y+=i;
        if(y==1) {
            y++; cnt++;
        }
        cnt+=cntR(x, y);
        res = min(res, cnt);
    }
    
    if(n<0) {
        ll cnt=0;
        if(b==1) {
            b++; cnt++;
        }
        res=min(res, cnt+cntR(a, b));
    }
    cout<<res<<endl;
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
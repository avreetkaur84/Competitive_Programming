// Question Link - https://codeforces.com/problemset/problem/2020/A

#include <bits/stdc++.h>
#define ll long long
using namespace std;

// Brute force intution lead to TLE -> forced me to learn base-k concept.
// ess function mein jab tak k^x small hai n se, tab tak x++ hotta rahega, and maxx small k^x return ho jayega.
// Then, returned cur subtract karenge n se, and jitni bar yeh fucntion call hogga utni bar cnt++ hogga.


void solve() {
    ll n, k;  cin>>n>>k;
    ll cnt=0; vector<int> res;

    if(k==1) {
        cout<<n<<endl; return;
    }

    while(n>0) { 
        int r = n%k;
        n = n/k;
        res.push_back(r);
    }

    cnt = accumulate(res.begin(), res.end(), 0);
    
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
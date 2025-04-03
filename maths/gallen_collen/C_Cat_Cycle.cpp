// Question Link - https://codeforces.com/gym/348180/problem/C

// Amazing problem!!!!

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

// in circular array - to find the idx, we simply do - (k%n) -> k-no. of moves, n->total position
// but for 1 idx -> we do -> 1+(k%n) = idx

void solve() {
    ll n, k;    cin>>n>>k;
    k--;    // to find the no. of moves, as k is the hour
    
    // cats will never clash in the even seats
    if(n%2==0) {
        // finding idx in 1 based
        cout<<1+(k%n)<<endl;    return;
    } else {
        // find intersections
        // (n-1)/2 -> no. of cycles, or moves after which intersection will occur
        ll intersections = k/((n-1)/2);
        cout<<1+(k+intersections)%n<<endl;  return;
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
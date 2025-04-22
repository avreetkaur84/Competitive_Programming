// Question Link - https://codeforces.com/problemset/problem/1374/B

// I am unable to get this question
// I have solved this question fully on my own without any external help, just with shift of my mindset.

#include <bits/stdc++.h>
#define ll long long
using namespace std;



void solve() {
    ll n;   cin>>n;
    ll cnt=0;

    while(n>0) {
        if(n==1) {
            cout<<cnt<<endl;    return;
        }

        if(n%6!=0) {
            n=n*2;
            cnt++;
        }

        if(n%6==0) {
            n/=6;
            cnt++;
        } else {
            cout<<-1<<endl; return;
        }

    }

    cout<<-1<<endl;
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
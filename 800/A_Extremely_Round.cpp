// Question Link - https://codeforces.com/problemset/problem/1766/A

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int calDigit(ll num) {
    int cnt=0;
    while(num>0) {
        num/=10;
        cnt++;
    }

    return cnt;
}

pair<int, int> generateNum(int cnt) {
    int b=(int)pow(10, cnt);
    b=b/10;
    int a=(b-1);
    return {b, a};
}

void solve() {
    ll n; cin>>n;
    int n_digit=calDigit(n);
    // cout<<"cnt: "<<n_digit<<"   ";

    if(n_digit==1) {
        cout<<n<<endl; return;
    }

    auto res = generateNum(n_digit);
    // cout<<"zeros: "<<res.first<<"   ";
    // cout<<"ones: "<<res.second<<"   ";

    int moves=n/res.first;
    int nines=res.second;
    int zeros=res.first;

    while(nines>0 && zeros>0) {
        if(zeros==10 || zeros==1) {
            zeros=1;
            moves+=9;
            break;
        }  

        zeros/=10;
        moves+=(nines/zeros);
        nines/=10; 
    }

    cout<<moves<<endl;
    
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
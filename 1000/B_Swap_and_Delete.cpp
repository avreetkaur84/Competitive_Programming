// Question Link - https://codeforces.com/problemset/problem/1913/B

#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    string s;   cin>>s;
    ll z_cnt=0, o_cnt=0;
    // ll moves=0;

    for(ll i=0; i<s.length(); i++) {
        if(s[i]=='0')  z_cnt++;
        else o_cnt++;
    }

    for(int i=0; i<s.length(); i++) {
        if(s[i]=='0' && o_cnt>0)   o_cnt--;
        else if(s[i]=='1' && z_cnt>0) z_cnt--;
        else {
            break;
        }
    }

    // ll moves=abs(z_cnt-o_cnt);
    // // cout<<"moves: "<<moves<<"   ";
    // ll rem = s.length()-moves;

    // if(rem%2!=0)    moves++;
    // else moves=moves+(rem/2)+1;
    

    cout<<z_cnt+o_cnt<<endl;
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
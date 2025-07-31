// Question Link - https://codeforces.com/problemset/problem/1659/A

#include <bits/stdc++.h>
#define ll long long
using namespace std;

/*
    Nice maths question. I lack in deriving the formula from question parameters and contraints, instead I observe the patterns over examples and then try to contruct an formula which is dangerous. I need to work on this.
*/

void solve() {
    int n, r, b;  cin>>n>>r>>b;
    string s="";
    // distribute in b+1 segments, so, each segment will have minimum:
    int m = r/(b+1);
    // few will have m+1 
    int rem = r%(b+1);

    s+=string(m, 'R'); 
    if(rem>0) {
        s+='R'; rem--;
    }
    while(b--) {
        s+='B';
        s+=string(m, 'R');
        if(rem>0) {
            s+='R'; rem--;
        }
    }

    cout<<s<<endl;
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
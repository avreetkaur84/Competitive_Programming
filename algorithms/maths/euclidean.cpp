// for calculating the gcd 

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

// a needs to be greater
int euclidean(int a, int b) {
    if(b==0) return a;
    if(b>a) swap(a, b);

    return euclidean(b, a%b);
}

// lcm -> lowest common multiple
// factorise both and store their value in set and then take the common small value
set<int> fac(int x) {
    int i=2; set<int> st;
    while(x>0) {
        while(x%i==0) {
            x=x/i; st.insert(i);
        }
        i++;
    }
    return st;
}

int lcm(int x, int y) {
    set<int> a = fac(x);
    set<int> b = fac(y);
    for(auto it : a) {
        if(b.count(it)) return it;
    }

    return -1;
}

int main()
{
    int a=7, b=14;   
    // cin>>a>>b;
    int res = euclidean(a, b);
    cout<<lcm(a, b)<<"\n";
    // cout<<res<<endl;
}
// for calculating the gcd 

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

// a needs to be greater
int euclidean(int a, int b) {
    if(b==0)    return a;
    if(b>a) swap(a, b);

    return euclidean(b, a%b);
}



int main()
{
    int a=7, b=14;   
    // cin>>a>>b;
    int res = euclidean(a, b);
    cout<<res<<endl;
}
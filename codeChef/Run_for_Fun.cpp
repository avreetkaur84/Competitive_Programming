// Question Link - 

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

// void solve() {
    
// }



int main()
{
    int y, x;
    cin >> y>>x;
    int res;

    // if(x==y)  {
    //     cout<<0<<endl;
    // }
    if(x%y==0) {
        res = floor(double(x)/y)-1;
    } else res = floor(double(x)/y);
    cout<<res<<endl;
}
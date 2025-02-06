#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void solve() {
    int X, Y; cin>>X>>Y;
    // double num=0;
    string num="";
    int k=1; 
    
    while(k<=(X+Y)) {
        if(k<=(X/2)) num = num+'1';
        else if(k<=((X/2)+Y)) num = num+'2';
        else if(k<=(X+Y)) num = num+'1';
        k++;
    }
    
    // (X/2) <=
    // ((X/2)+Y)<=

    cout<<num<<endl;
}

int main() {
	// your code goes here
    int T; cin>>T;
    while(T--) {
        solve();
    }
}
// Question Link - 

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void solve() {
    string word; cin>>word;
    // cout<<word<<endl;

    if(word.length()>=2) {
        word = word.substr(0, word.length()-2);
        word = word+"i";
    }

    // if(word.length()==2)    word = "i";
    // if(word.length()==0)    word = "us";

    cout<<word<<endl;
}

int main()
{
    int t; cin>>t;
    while(t--) solve();
}
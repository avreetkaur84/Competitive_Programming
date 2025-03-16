// Question Link - https://codeforces.com/problemset/problem/1881/A

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// string s characters needs to be subset of string x characters. we can check this only by traversing, but we can't just traverse to check this as it will be inefficient.
// There will be two cases-
// 1. x length is greater than s - find between or by reordering first and last.
// 2. x length is smaller than s - need to convert x into s.

void solve()
{
    int n, m;
    cin >> n >> m;
    string x;   cin >> x;
    string s;   cin >> s;
    // int cnt = 0;

    int count=-1;
	for(int i=0;i<=5;i++){
	  if(x.find(s)!=-1){
	     count=i; 
         break;
       }
	     x+=x;
	}
	cout<<count<<endl;

    // while(x.length()<s.length()) {
    //     x=x+x;  cnt++;
    // }

    // int i=0, j=0;
    // while(j<x.length()) {
    //     if(x==s)  {
    //         cout<<cnt<<endl;    return;
    //     }
    //     if(cnt>5) {
    //         cout<<-1<<endl; return;
    //     }
        
    //     if((x.substr(i, j-i+1)==s.substr(0, j-i+1)) && (j-i+1)<=s.length()) {
    //         j++;
    //     } else {
    //         i=i+1;  j++;
    //     }

    //     // if(j==x.length()) {
    //     //     x=x+x; cnt++; j=0; i=0;
    //     // }
    // }

    // cout<<cnt<<endl;
 }

    int main()
    {
        int t;
        cin >> t;

        while (t--)
        {
            solve();
        }
    }
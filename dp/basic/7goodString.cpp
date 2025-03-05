// Question Link - https://www.geeksforgeeks.org/problems/better-string/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=better-string

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void print(vector<int> &dp) {
    cout<<"Dp values: ";
    for(int &x : dp)    cout<<x<<"  ";
    cout<<endl;
}

void seqCal(string str, vector<int> &dp) {
    dp[0]=2;
    map<char, int> mp;
    
    mp[str[0]]=0;
    
    for(int i=1; i<str.length(); i++) {
        dp[i]=dp[i-1]*2;
        
        // logic for checking if same character as str[i] has appeared before in string, if yes, then at what index last index.
        if(mp.find(str[i])!=mp.end()) {
            int val = mp[str[i]];    //got char index
            int seq = 1;
            
            if(val>0) seq = dp[val-1];
            // if(val==0) seq=1;
            dp[i] -= seq;
        }
        
        mp[str[i]] = i;
    }
}


string betterString(string str1, string str2) {
    int n1=str1.length(), n2=str2.length();
    vector<int> dp1(n1, -1); 
    vector<int> dp2(n2, -1);
    
    seqCal(str1, dp1);
    seqCal(str2, dp2);
    
    // print(dp1);
    // print(dp2);
    
    int cnt1 = dp1[n1-1];
    int cnt2 = dp2[n2-1];
    
    if(cnt1>=cnt2)   return str1;
    else  return str2;
}

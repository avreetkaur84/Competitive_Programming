// Question Link - 

#include <bits/stdc++.h>
#define ll long long
using namespace std;

// AC code
class Approach2 {
public:
    int characterReplacement(string s, int k) {
        int i=0, j=0, maxx=0, n=s.size(), max_freq=0;
        unordered_map<char, int> mp;


        while(j<n) {
            mp[s[j]]++;
            max_freq=max(max_freq, mp[s[j]]);

            if(((j-i+1)-max_freq) > k) {
                mp[s[i]]--; i++;
            }

            maxx=max(maxx, j-i+1);
            // cout<<"i: "<<i<<"   j: "<<j<<"   max_freq: "<<max_freq<<"   maxx: "<<maxx<<endl;
            j++;
        }
        return maxx;
    }
};

// First approach  - WA - Way too complex, usage of many if's and variables
class Approach1 {
public:
    int characterReplacement(string s, int k) {
        int i=0, j=0, maxx=0, ch_idx=0, n=s.size(), cnt=k, ch_cnt=0;
        bool flag=false; 

        // if(k==0)    return 0;
        // cout<<"size: "<<n<<endl;

        while(j<n) {
            if(s[i]!=s[j]) {
                if(cnt>0) {
                    cnt--;
                    if(flag==false) {
                        ch_idx=j; flag=true;
                        ch_cnt++;
                    }
                } else {
                    if(k>0) {
                        i=ch_idx; j=i;
                        cnt=k; flag=false;
                    } else {
                        i=j;
                    }
                }
            }
            
            int x=0;
            if(cnt>0 && j==n-1 && ch_cnt>0) {
                x=min(cnt, n-(j-i+1));
                // cout<<"x: "<<x<<endl;
            }

            maxx=max(maxx, j-i+1+x);
            if(maxx>n)   maxx=n;
            // cout<<"i: "<<i<<"   j: "<<j<<"   cnt: "<<cnt<<"   ch_cnt: "<<ch_cnt<<"   maxx: "<<maxx<<endl;
            j++;
        }
        return maxx;
    }
};
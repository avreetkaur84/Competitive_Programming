// Question Link - https://www.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1

#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Solution1 {
  public:
    int longestKSubstr(string &s, int k) {
        // your code here
        int i=0, j=0, maxx=-1, n=s.length();
        unordered_map<char, int> mp;
        
        while(j<n) {
            mp[s[j]]++;
            
            while(mp.size()>k) {
                mp[s[i]]--; 
                if(mp[s[i]]==0) {
                    mp.erase(s[i]); i++; break;
                }
                i++;
            }
            
            if(mp.size()==k)  maxx = max(maxx, j-i+1);
            // cout<<"i: "<<i<<"   j: "<<j<<"  maxx: "<<maxx<<endl;
            
            j++;
        }
        
        return maxx;
    }
};

class Solution2 {
  public:
    int longestKSubstr(string &s, int k) {
        // Taking note of last index
        int i=0, j=0, maxx=-1, n=s.length();
        unordered_map<char, int> mp;
        
        while(j<n) {
            mp[s[j]]++;
            
            if (mp.size()>k) {
                int minn=INT_MAX;
                char x;
                for(auto g:mp) {
                    if(g.second<minn) {
                        x=g.first;
                    }
                }
                
                i=mp[x]+1; mp.erase(x);
            }
            
            if(mp.size()==k)  maxx = max(maxx, j-i+1);
            // cout<<"i: "<<i<<"   j: "<<j<<"  maxx: "<<maxx<<endl;
            
            j++;
        }
        
        return maxx;
    }
};
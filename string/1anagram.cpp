// Question Link - https://leetcode.com/problems/valid-anagram/

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Solution {
    public:
        bool isAnagram(string s, string t) {
            if(s.length()!=t.length())  return false;
            unordered_map<char, int> mp;
    
            for(int i=0; i<s.length(); i++) {
                mp[s[i]]++;  
                mp[t[i]]--;  
            }
    
            for(const auto& pair : mp) {
                if(pair.second!=0)  return false;
            }
    
            return true;
        }
    };
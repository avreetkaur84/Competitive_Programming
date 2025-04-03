// Question Link - https://leetcode.com/problems/sort-characters-by-frequency/

// Learnt lambda and append function
// Also, new way to use sort function

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Solution {
    public:
        string frequencySort(string s) {
            string res="";
            unordered_map<char, int> mp;
            for(int i=0; i<s.length(); i++) {
                mp[s[i]]++;
            }
    
            vector<char> arr;
            for(const auto& pair : mp) {
                arr.push_back(pair.first);
            }
            
            // bool compare(char a, char b) {
            //     return cnt[a]>cnt[b];
            // }
    
            // used lambda function
            sort(arr.begin(), arr.end(), [&](char a, char b) {
                return mp[a]>mp[b];
            });
    
            int i=0;
            // while(i<arr.size()) {
            //     if(mp[arr[i]]>0) {
            //         res+=arr[i];
            //         mp[arr[i]]--;
            //     } else i++;
            // }
    
            // OPTIMIZED VERSION OF ABOVE
            // append ch character mp[ch] times
            for(char ch : arr) {
                res.append(mp[ch], ch);
            }
    
            cout<<res<<endl;
            return res;
        }
    };
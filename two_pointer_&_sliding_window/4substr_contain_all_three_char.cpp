// Question Link - https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/description/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
        int i = 0, j = 0, cnt = 0, n = s.length();
        unordered_map<char, int> mp;
        mp['a']=-1; mp['b']=-1; mp['c']=-1;

        if (s.length() < 3) return s.length();

        for (int i = 0; i < n; i++) {
            mp[s[i]]=i;

            if(mp['a']>-1 && mp['b']>-1 && mp['c']>-1) {
                cnt+=min(mp['a'], min(mp['b'], mp['c']))+1;
            }

            // cout<<"a: "<<mp['a']<<"  b: "<<mp['b']<<"    c: "<<mp['c']<<endl;
        }

        return cnt;
    }
};

int main() {
    cout<<"Working"<<endl;
}
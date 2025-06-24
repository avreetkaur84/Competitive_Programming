// Question Link - https://leetcode.com/problems/reverse-words-in-a-string/solutions/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

/*
    In my april solution I made the string by following the reverse order lik goinf from n-1 to 0, but in June slution, I am doing it directly by going from 0 to n-1 and I am not reversing the word, as we havae to add it directly but just need to reverse the order of words, so I think I have saved that extra ittle operation here, and june code is more cleaner version. 
*/

// 4 April, 2025 - 
class Solution1 {
public:
    string reverseWords(string s) {
        int n=s.length()-1;

        // skip whitespaces - at the start and end of string
        int e=n; int b=0;
        while(s[e]==' ')    e--;
        while(s[b]==' ')    b++;

        string word="";
        string res="";
        for(int i=e; i>=b; i--) {
            if(s[i]==' ' && s[i+1]!=' ' && i>0) {
                reverse(word.begin(), word.end());
                res += word+' ';
                word="";
            } else if(s[i]!=' ') word+=s[i];
        }
        
        reverse(word.begin(), word.end());
        res += word;

        return res;
    }
};

// 22 June, 2025
class Solution2 {
public:
    string reverseWords(string s) {
        int n=s.length();

        string word="", res="";
        for(int i=0; i<n; i++) {
            // if(s[i]==' ') -> skip
            if(s[i]!=' ') word+=s[i];
            else if(i>0 && s[i-1]!=' ' && s[i]==' ' && word.size()!=0) {
                if(res.size()==0) res=word;
                else res=word+" "+res;                 
                word="";
            }
        }

        if(word.size()!=0) {
            if(res.size()==0) res=word;
            else res=word+" "+res; 
        }

        return res;
    }
};
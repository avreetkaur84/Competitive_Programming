// Question Link - https://leetcode.com/problems/largest-odd-number-in-string/description/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

/*
    To be honest right now, I can't get what I did in sep solution, like traversed from start and stuff which is I guess blunder. Because question asked to return the largest odd number, so, we know that for number to be largest odd, we need to have odd bit at the righmost side, so In june solution I directly traversed from right to left and for checking odd, I performed bit manipulation which is faster.
*/


// 9 september, 2024 slution
class Solution {
public:
    string largestOddNumber(string num) {
        int len=num.size();
        int index=-1;
        string str="";
        for(int x=0;x<len;x++)
        {
            if((num[x]-'0')%2==1)
            index=x;
        }
        if(index==-1)
        return str;
        else
        {
            for(int x=0;x<=index;x++)
            str+=num[x];
            return str;
        }
    }
};

// 22 june, 2025 solution
class Solution {
public:
    string largestOddNumber(string num) {
        for(int i=num.size()-1; i>=0; i--) {
            if((num[i]-'0')&1) return num.substr(0, i+1);
        }

        return "";
    }
};
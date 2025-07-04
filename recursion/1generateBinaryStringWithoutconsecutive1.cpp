// Question Link - https://www.geeksforgeeks.org/problems/generate-all-binary-strings/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card


#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    void generate(char s[], int num, int k, vector<string> &res) {
        if(k==num) {
            s[k]='\0';
            res.push_back(s);
            return;
        }
        
        if(s[k-1]=='0') {
            s[k]='0';
            generate(s, num, k+1, res);
            
            s[k]='1';
            generate(s, num, k+1, res);
        }
        
        if(s[k-1]=='1') {
            s[k]='0';
            generate(s, num, k+1, res);
        }
        
    }

    vector<string> generateBinaryStrings(int num){
        char s[num+1];
        vector<string> res;
        
        if(num==0)  return res;
        
        s[0] = '0';
        generate(s, num, 1, res);
        
        s[0] = '1';
        generate(s, num, 1, res);
        
        return res;
    }
};

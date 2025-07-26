// Question Link - https://leetcode.com/problems/word-ladder/description/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

// Finally got this correct!!! It just made me cry seriously, and gave very bad headache, but despite what so ever, I conquered it!!!!
/*
    Key Learnings:
    1. If you can't think of any solution for a problem, just try to break it into smaller problems, and just think how you will solve it on notebook, or in real life. After solving hard questions or complex questions I have realised this fact. Even if you think your approach is stupid, at least try it. Something is better than nothing!!!
*/

class Solution {
public:
    // if endWord is not in worList return 0
    // used set bcz set searching time is O(1) and also deletion time is O(1)
    bool check(string beginWord, string &endWord, set<char> &alp, set<string> &st, queue<string> &q) {
        for(int i=0; i<beginWord.size(); i++) {
            string temp=beginWord;
            for(auto ch : alp) {
                temp[i]=ch;
                if(st.find(temp)!=st.end()) {
                    // cout<<temp<<endl;
                    st.erase(temp); q.push(temp);
                    if(temp==endWord) return true;
                }
            }
        }

        return false;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<char> alp = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
        set<string> st; int n=wordList.size(), cnt=0;
        queue<string> q; q.push(beginWord);
        for(int i=0; i<n; i++) st.insert(wordList[i]);
        // cout<<st.size()<<endl;

        if(st.find(endWord)==st.end()) return 0;
        if(st.find(beginWord)!=st.end()) st.erase(beginWord);

        while(!q.empty()) {
           int qsize=q.size(); cnt++;
        //    cout<<cnt<<"  "<<qsize<<endl;
           for(int i=0; i<qsize; i++) {
              string word=q.front(); q.pop();
              bool flag = check(word, endWord, alp, st, q);
              if(flag==true) {
                cnt++; return cnt;
              }
           }
        }

        return 0;
    }
};

/*
    The first approch with which I have solved the question is greedy, therefore it won't give the shortest trabsformation sequence
*/

// First Approach
class Solution {
public:
    // if endWord is not in worList return 0
    bool check(string &beginWord, set<char> &alp, set<string> &st) {
        for(int i=0; i<beginWord.size(); i++) {
            string temp=beginWord;
            for(auto ch : alp) {
                temp[i]=ch;
                if(st.find(temp)!=st.end()) {
                    beginWord=temp; st.erase(beginWord); return true;
                }
            }
        }

        return false;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<char> alp = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
        set<string> st; int n=wordList.size(), cnt=0;
        for(int i=0; i<n; i++) st.insert(wordList[i]);

        if(st.find(endWord)==st.end()) return 0;

        while(beginWord!=endWord && !st.empty()) {
            bool flag = check(beginWord, alp, st);
            if(!flag) return 0;
            cnt++;
        }

        return cnt;
    }
};
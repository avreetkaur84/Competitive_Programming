// Question Link - https://leetcode.com/problems/word-ladder-ii/description/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

/*
    ALGORITHM:
    1. Count the minimum steps required to achieve the target.
    2. Use the dfs to traverse all the routes with depth min cnt that lead to target.
    3. Now, in order to do the traversal in right path, we have to create a graph that shows the path. Now, its means, we have to create the adjacency list. And, we will use map to store the maped words.
    4. Now, in order to create the adjacency list, we need to have the visited map, that stores the level of each node, as on basis of this level we will determine the adjacency list.
    5. Once, adjacency list is created it is piece of cake to traverse the graph.
*/



// I got fucking TLE after passing 33/38 test cases. Awwwwwwww, dude, it really hurts!!! Need to change the approach :((( 
// But got AC on gfg!!!
class Solution {
public:
    void helper(string cur_word, unordered_set<string> &st, string alp, queue<string> &q, unordered_map<string, int> &vt, unordered_map<string, vector<string>> &adj, unordered_set<string> &lst) {
        for(int i=0; i<cur_word.size(); i++) {
            string temp = cur_word;
            for(auto it : alp) {
                temp[i]=it;
                if(st.find(temp)!=st.end()) {
                    if(lst.find(temp)==lst.end()) {
                        q.push(temp); vt[temp]=vt[cur_word]+1; lst.insert(temp);
                    }
                    adj[cur_word].push_back(temp);
                }
            }
        }
    }

    void dfs(string cur, string endWord, vector<string> path, vector<vector<string>> &res, int cnt, unordered_map<string, vector<string>> &adj, unordered_map<string, int> &vt) {
        if(cnt<=0) return;
        if(cur==endWord) {
            res.push_back(path); return;
        }

        for(auto it : adj[cur]) {
            if(vt[it]==vt[cur]+1) {
                path.push_back(it);  dfs(it, endWord, path, res, cnt-1, adj, vt);  path.pop_back();
            }
        }
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        int n=wordList.size();
        unordered_set<string> st; 
        queue<string> q;    // queue will store the string arrays accroding to level
        unordered_map<string, int> vt; unordered_map<string, vector<string>> adj;

        string alp = "abcdefghijklmnopqrstuvwxyz";
        for(int i=0; i<n; i++) st.insert(wordList[i]);
        if(st.find(endWord)==st.end()) return {};
        q.push(beginWord);  st.erase(beginWord); vt[beginWord]=0;
        int depth=0;  

        while(!q.empty()) {
            int q_size=q.size(); 
            // cout<<q_size<<endl;

            unordered_set<string> lst = {};
            for(int i=0; i<q_size; i++) {
                string cur_word = q.front(); q.pop();
                helper(cur_word, st, alp, q, vt, adj, lst);
            }

            for(auto it : lst) st.erase(it);
        }

        if(vt.find(endWord)!=vt.end()) {
            depth=vt[endWord]+1;
        }

        // cout<<depth<<endl;
        vector<vector<string>> res;
        dfs(beginWord, endWord, {beginWord}, res, depth, adj, vt);

        return res;
    }
};
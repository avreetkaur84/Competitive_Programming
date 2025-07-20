// Question Link - https://leetcode.com/problems/asteroid-collision/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

/*
    There was gap in my understanding of question, my focus was on performing operation rather than understanding in detail what exactly I need to solve: BIG RED FLAG!!
    
*/

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n=asteroids.size();
        queue<pair<int, int>> q; int pos=0, neg=0;

        for(int i=0; i<n; i++) {
            q.push({asteroids[i], i}); 
            if(asteroids[i]>=0) pos++;
            else neg++;
        }

        while(!q.empty()) {
            if(pos==0 || neg==0) break;
            pair<int, int> a=q.front(); q.pop();
            pair<int, int> b=q.front(); 

            if(a.first>=0 && b.first<0 || a.first<0 && b.first>=0) {
                q.pop();
                if(abs(b.first)<a.first) {
                    q.push(a); 
                    if(b.first>=0) pos--;
                    else neg--;
                }
                else if(abs(b.first)>a.first) {
                    q.push(b);
                    if(a.first>=0) pos--;
                    else neg--;
                } else {
                    if(b.first>=0) pos-=2;
                    else neg-=2;
                }
            } else q.push(a);
        }

        vector<int> res;
        vector<pair<int, int>> temp;
        
        while(!q.empty()) {
            temp.push_back(q.front()); q.pop();
        }

        sort(temp.begin(), temp.end(), [](auto &a, auto &b) {
            return a.second<b.second;
        });

        for(int i=0; i<temp.size(); i++) res.push_back(temp[i].first);

        return res;
    }
};
// Question Link - 

#include <bits/stdc++.h>
#define ll long long
using namespace std;

/*
    Coding the optimised version really felt like an accomplishment, it took me fucking one hour, but ya did it, coded everything from scratch, but yesterday, I took optimised solution intution hint from tutorail, but today, coded everything own my own from scratch.
    Things I learnt - 
    1. Index manipulation, like earlier I thought of just taking the alternative elements from oth arrays, like A[1]+B[2] and B[1]+A[2], like this, but then I resalised what if B array contains all small elements, and K large elemenst become by iterating A arrays and only taking B first element, then this approach will fail
    2. After this, I thought of keeping track of indexes, like if A[1]+B[2] is giving max, then next time, I need to check A[1]+B[3] and so on. 
    3. Used the set for not repeating the same index again.
    4. Again I ignored the edge cases, like didn't handle them well - 
*/

// BRUTE FORCE - GOT TLE
class Solution {
  public:
    
    vector<int> maxCombinations(int N, int K, vector<int> &A, vector<int> &B) {
        priority_queue<int, vector<int>, greater<int>> hp;
        sort(A.begin(), A.end(), [](int a, int b) {
            return a > b;
        });
        
        sort(B.begin(), B.end(), [](int a, int b) {
            return a > b;
        });
        
        vector<int> res;
        for(int i=0; i<A.size(); i++) {
            for(int j=0; j<B.size(); j++) {
                hp.push(A[i]+B[j]);
                if(hp.size()>K) hp.pop();
            }
        }
        
        while(!hp.empty()) {
            res.push_back(hp.top()); hp.pop();
        }
        
        reverse(res.begin(), res.end());
        
        return res;
        
    }
};

// OPTIMISED VERSION
vector<int> maxCombinations(int N, int K, vector<int> &A, vector<int> &B) {
        priority_queue<pair<int, pair<int, int>>> hp;
        set<pair<int, int>> st;
        sort(A.begin(), A.end(), [](int a, int b) {
            return a > b;
        });
        
        sort(B.begin(), B.end(), [](int a, int b) {
            return a > b;
        });
        
        hp.push({A[0]+B[0], {0,0}}); st.insert({0,0});
        vector<int> res; int first=0, second=0;
        
        while(res.size()<K && !hp.empty()) {
            pair<int, pair<int, int>> temp = hp.top(); 
            res.push_back(temp.first); hp.pop();
            
            first = temp.second.first;
            second = temp.second.second;
            
            if(second+1 < N && st.find({first, second+1}) == st.end()) {
                hp.push({A[first]+B[second+1], {first, second+1}});
				st.insert({first, second+1});
            }

            if(first+1 < N && st.find({first+1, second}) == st.end()) {
                hp.push({A[first+1]+B[second], {first+1, second}});   
				st.insert({first+1, second});
            }
        }
        
        return res;
        
    }
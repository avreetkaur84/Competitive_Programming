// Question Link - https://www.geeksforgeeks.org/problems/reverse-a-stack/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=reverse-a-stack

// Dry this on notebook for understanding in depth

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Solution{
    public:
        void insert(int n, stack<int> &st) {
            if(st.size()==0)    st.push(n);
            else {
                int x = st.top();
                st.pop();
                insert(n, st);
                
                st.push(x);   
            }
        }
    
        void Reverse(stack<int> &St){    
            if(!St.empty()) {
                int x = St.top();
                St.pop();
                Reverse(St);
                
                insert(x, St);
            }
        }
    };
// Question Link - https://leetcode.com/problems/partition-list/description/

#include <bits/stdc++.h>
#define ll long long
using namespace std;


//  Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

 class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        queue<ListNode*> q;
        set<ListNode*> st;

        ListNode* mover = head;
        while(mover) {
            if(mover->val<x) st.insert(mover);
            else q.push(mover);
            mover = mover->next;
        }

        ListNode* head2 = nullptr;
        mover = nullptr;
        for(auto it : st) {
            if(!head2) {
                head2=it;
                mover = it;
            } else {
                mover->next = it;
                mover = mover->next;
            }
            if(mover) mover->next=nullptr;
        }

        while(!q.empty()) {
            ListNode* it = q.front();
            q.pop();
            if(!head2) {
                head2=it;
                mover=it;
            } else {
                mover->next = it;
                mover = mover->next;
            }
            if(mover) mover->next=nullptr;
        }

        return head2;
    }
};
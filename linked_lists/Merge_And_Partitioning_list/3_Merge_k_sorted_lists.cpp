// Question Link - https://leetcode.com/problems/merge-k-sorted-lists/description/

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

 struct comp {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val>b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // we want min at top
        priority_queue<ListNode*, vector<ListNode*>, comp> pq;
        for(auto it : lists) {
            if(!it) continue;
            pq.push(it);
        }

        ListNode* head = nullptr;
        ListNode* mover = nullptr;

        while(!pq.empty()) {
            ListNode* cur = pq.top();
            pq.pop();
            if(!head) {
                head = cur;
                mover = cur;
            } else {
                mover->next = cur;
                mover=mover->next;
            }
            if(cur->next) pq.push(cur->next);
            if(mover) mover->next=nullptr;
        }

        return head;
    }
};
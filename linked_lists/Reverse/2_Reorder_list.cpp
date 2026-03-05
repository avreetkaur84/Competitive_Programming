// Question Link - https://leetcode.com/problems/reorder-list/

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
    void reorderList(ListNode* head) {
        if(!head || !head->next || !head->next->next) return;
        ListNode* slow = head;
        ListNode* fast = head;        

        while(fast!=nullptr && fast->next!=nullptr) {            
            slow = slow->next;
            fast = fast->next->next;
        }

        // cout<<slow->val<<"\n";
        ListNode* cur = slow->next;
        slow->next = nullptr;
        ListNode* prev = nullptr;
        while(cur!=nullptr) {
            ListNode* temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
        }

        ListNode* mover1=head;
        ListNode* mover2=prev;
        // cout<<mover1->val<<" "<<mover2->val<<"\n";
        
        while(mover1!=nullptr && mover2!=nullptr) {
            // cout<<mover1->val<<" "<<mover2->val<<"\n";
            ListNode* t1=mover1->next;
            mover1->next = mover2;
            
            ListNode* t2=mover2->next;
            mover2->next = t1;
            
            mover1=t1;
            mover2=t2;
        }
    }
};
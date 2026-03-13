// Question Link - https://leetcode.com/problems/remove-nodes-from-linked-list/description/

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
    ListNode* removeNodes(ListNode* head) {
        auto rev = [&](ListNode* cur) -> ListNode* {
            ListNode* prev = nullptr;

            while(cur) {
                // cout<<cur->val<<" ";
                ListNode* temp = cur->next;
                cur->next = prev;
                prev = cur;
                cur = temp;
            }

            return prev;
        };

        ListNode* mover = rev(head);
        ListNode* newHead = nullptr;
        ListNode* temp = nullptr;
        int maxx=0;

        while(mover) {
            // cout<<mover->val<<" ";
            if(mover->val>=maxx) {
                if(!newHead) {
                    newHead = mover;
                    temp = mover;
                } else {
                    temp->next = mover;
                    temp = temp->next;
                }
                maxx=mover->val;
            }
            mover=mover->next;
            if(temp) temp->next=nullptr;
        }

        newHead = rev(newHead);
        return newHead;
    }
};
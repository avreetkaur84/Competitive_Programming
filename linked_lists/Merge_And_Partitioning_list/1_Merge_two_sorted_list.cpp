// Question Link - https://leetcode.com/problems/merge-two-sorted-lists/description/

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = nullptr;
        ListNode* mover = nullptr;

        while(list1!=nullptr && list2!=nullptr) {
            if(list1->val<list2->val) {
                if(!head) {
                    head = list1;
                    mover = list1;
                } else {
                    mover->next = list1;
                    mover=mover->next;
                }
                list1=list1->next;
            } else {
                if(!head) {
                    head = list2;
                    mover = list2;
                } else {
                    mover->next = list2;
                    mover=mover->next;
                }
                list2=list2->next;
            }
        }

        while(list1!=nullptr) {
            if(!head) {
                head = list1;
                mover = list1;
            } else {
                mover->next = list1;
                mover=mover->next;
            }
            list1=list1->next;
        }

        while(list2!=nullptr) {
            if(!head) {
                head = list2;
                mover = list2;
            } else {
                mover->next = list2;
                mover=mover->next;
            }
            list2=list2->next;
        }

        return head;
    }
};
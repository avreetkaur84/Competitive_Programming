// Question Link - https://leetcode.com/problems/reverse-linked-list-ii/description/

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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head || !head->next) return head;
        ListNode* temp = head;
        for(int i=1; i<left-1; i++) {
            temp = temp->next;
        }

        ListNode* mover = (left>1)?temp->next:head;
        ListNode* start = mover;
        ListNode* end = mover;

        for(int i=left; i<=right; i++) {
            end = end->next;
        }

        ListNode* prev=nullptr;
        ListNode* cur=start;
        while(cur!=end) {
            ListNode* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }

        if(left>1) temp->next = prev;
        else head=prev;
        start->next = end;

        return head;
    }
};
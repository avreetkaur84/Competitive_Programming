// Question Link - https://leetcode.com/problems/palindrome-linked-list/description/

#include <bits/stdc++.h>
#define ll long long
using namespace std;


//  Definition for singly-linked list.
 struct ListNode {
     int val;
      ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

 class Solution {
public:
    bool isPalindrome(ListNode* head) {
        // find the mid point using fast and slow pointer
        // reverse the last half 
        // start comparing from the head to the middle last
        ListNode* slow=head;
        ListNode* fast=head;

        while(fast!=nullptr && fast->next!=nullptr) {
            slow=slow->next;
            fast=fast->next->next;
        }

        // slow is the middle point : reverse
        ListNode* prev=nullptr;
        ListNode* cur=slow;
        while(cur!=nullptr) {
            ListNode* temp=cur->next;
            cur->next=prev;
            prev=cur;
            cur=temp;
        }

        ListNode* start=head;
        ListNode* mid=prev;
        while(mid!=nullptr && start!=nullptr && start!=mid) {
            if(mid->val!=start->val) return false;
            mid=mid->next;
            start=start->next;
        }

        return true;
    }
};
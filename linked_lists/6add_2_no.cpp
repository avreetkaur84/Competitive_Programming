// Question Link - https://leetcode.com/problems/add-two-numbers/description/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

/*
    This question fucked up mind!!! It really tests the linked list basics. 
*/

//  * Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* mover1 = l1;
        ListNode* mover2 = l2;        
        ListNode* newHead = nullptr;
        ListNode* newList = newHead;
        int carry = 0;

        while(mover1!=nullptr || mover2!=nullptr) {
            int m1 = mover1!=nullptr ? mover1->val : 0;
            int m2 = mover2!=nullptr ? mover2->val : 0;
            int sum = m1 + m2 + carry;
            if(sum>9) carry=1;
            else carry=0;            

            ListNode* newNode = new ListNode(sum%10);
            // cout<<newNode->val<<endl;

            if(newHead==nullptr) {
                newHead=newNode; newList=newHead;
            } else {
                newList->next = newNode;
                newList = newList->next;
            }

            if(mover1) mover1=mover1->next; 
            if(mover2) mover2=mover2->next;
        }

        if(carry>0) newList->next = new ListNode(carry);

        return newHead;
    }
};


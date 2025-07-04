// Question Link - https://leetcode.com/problems/intersection-of-two-linked-lists/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

/*
        Brute force intution: SC-O(N) and TC-O(N)
        1. Creaet a set and insert A elements in it. And, then traverse B and match each node with set, if a node is found in set,means that node is intersecting node and we can return it.
        Got brute force intution+submission in 8 minutes

        Optimised Intutions:
        1. For space 0{1): I can compare all the nodes with each other, but tc will be O(M*N)
        2. Both A and B will have same nodes after intersection, so I acn first reach the last and then traverse backward untill nodes are same and when its different, I can return the previous node but its sunglt linked list so, I will fai!!!!! :(
        
        Required: TC:O(M+N), SC: O(1)
        3. For the final I got help from gpt, like not the code but just told it to ask me right questions and then with some hint, I figured this appraoch of using 2 pointer. In this approach, we will have moverA and moverB, initially poiting at headA and headA list repectively. The, if moverA==nullptr, then moverA will be headB and vice-versa. We are doing this, because A and B will trael the same distance til the intersection point as A and B starting length are different but after intersection their length is same. So, intersection point will be aat -  A+B or B+A.
    */

//  Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode* next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        set<ListNode*> st;

        ListNode* moverA = headA;
        while(moverA!=nullptr) {
            st.insert(moverA); moverA=moverA->next;
        }

        ListNode* moverB = headB;
        while(moverB!=nullptr) {
            if(st.find(moverB)!=st.end()) return moverB;
            moverB=moverB->next;
        }

        return NULL;
    }
};


// OPTIMISED
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* moverA = headA;
        ListNode* moverB = headB;

        while(moverA!=nullptr || moverB!=nullptr) {
            if(moverA==nullptr) moverA=headB;
            if(moverB==nullptr) moverB=headA;

            if(moverA==moverB) return moverA;
            moverA=moverA->next; moverB=moverB->next;
        }

        return NULL;
    }
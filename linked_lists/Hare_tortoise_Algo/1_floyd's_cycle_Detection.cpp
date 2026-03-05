// Question Link - https://leetcode.com/problems/linked-list-cycle-ii/
// Proof - https://leetcode.com/problems/linked-list-cycle-ii/solutions/5370700/easy-proof-beats-100-percent-users-floyd-1jnk/

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
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        int cnt = 0;

        while(fast!=nullptr && fast->next!=nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if(slow==fast) {
                slow=head;

                while(slow!=fast) {
                    slow=slow->next;
                    fast=fast->next;
                }
                return slow;
            }
        }
        return NULL;
        // return slow;
    }
};
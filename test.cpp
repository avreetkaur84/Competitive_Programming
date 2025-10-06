// Question Link - 

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

                            
#include <iostream>
#include <queue>
#include <sstream>
using namespace std;

// Definition for a
// binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    struct compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val>b->val;
        }
    };

    void traverseLL(ListNode* head, priority_queue<ListNode*, vector<ListNode*>, compare> &pq) {
        if(head==nullptr) return;

        while(head!=nullptr) {
            pq.push(head);
            head = head->next;
        }
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return nullptr;

        priority_queue<ListNode*, vector<ListNode*>, compare> pq;
        ListNode* head = nullptr;

        for(int i=0; i<lists.size(); i++) {
            if(lists[i]==nullptr) continue;
            traverseLL(lists[i], pq);
        }

        cout<<pq.size()<<endl;
        if(head==nullptr && !pq.empty()) {
            head = pq.top(); pq.pop();
        }

        ListNode* mover = head;

        while(!pq.empty()) {
            mover->next = pq.top(); 
            mover = mover->next;
            mover->next=nullptr;
            pq.pop();
        }

        return head;
    }
};
// Question Link - https://leetcode.com/problems/handling-sum-queries-after-update/description/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

// Segment Tree Updation using Lazy Propogration

class SegmentTree {
private: 
    vector<int> seg, lazy;
    vector<int> arr;

public:
    SegmentTree(vector<int> &a) {
        arr=a;
        seg.resize(4*arr.size(), 0);
        lazy.resize(4*arr.size(), 0);
        buildTree(0, 0, arr.size()-1);
    }

    int buildTree(int idx, int left, int right) {
        if(left==right) return seg[idx]=arr[left];
        int mid = (left+right)/2;
        int inter_1 = buildTree(2*idx+1, left, mid);
        int inter_2 = buildTree(2*idx+2, mid+1, right);
        return seg[idx]=inter_1+inter_2;
    }

    int calculation() {
        return seg[0];
    }
    
    // we are updating number of ones in range
    // update logic is wrong 
    int update(int idx, int start, int end, int left, int right) {
        // if not in left-right range, then don't go down that branch
        if(left>end || right<start) {
            return (lazy[idx])?(right-left+1)-seg[idx]:seg[idx];
        }
        
        // if already marked, first resolve this
        if(lazy[idx]) {
            lazy[idx]=0;
            seg[idx]=right-left+1-seg[idx];
            if(left!=right) {
                lazy[2*idx+1] = !lazy[2*idx+1];
                lazy[2*idx+2] = !lazy[2*idx+2];
            } 
        }

        if(left>=start && right<=end) {
            if(left!=right) {
                lazy[2*idx+1] = !lazy[2*idx+1];
                lazy[2*idx+2] = !lazy[2*idx+2];
            } 
            return seg[idx]=right-left+1-seg[idx];;
        }

        int mid = left+(right-left)/2;
        int inter_1 = update(2*idx+1, start, end, left, mid);
        int inter_2 = update(2*idx+2, start, end, mid+1, right);
        return seg[idx]=inter_1+inter_2;
    }
};

class Solution {
public:
    /*
        n1 and n2 -> q queries
        n1 only contains 0 and 1
        q1: flip 0,1 in [l,r] -> nums1
        q2: n2[i] += n1[i]*p
        q3: sum of all elements
        extra add -> (total_ones*q)
        we will have sum intially -> which will always be answer of q3 -> O(1) op
        for q2: sum += (total_ones_nums1*q) -> O(1) op
        for q1: we have to flip the number of 1, this is main, we will use segment tree to track the number of ones in range

        WTF!! Even segment tree failed, now I have to go for lazy propogation update, seriously:(
    */

    vector<long long> handleQuery(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        SegmentTree sg(nums1);
        int n=nums1.size();
        vector<long long> res;
        long long sum = accumulate(nums2.begin(), nums2.end(), 0ll);

        for(auto query : queries) {
            // cout<<sum<<" "<<sg.calculation()<<"\n";
            switch(query[0]) {
                case 1: {
                    sg.update(0, query[1], query[2], 0, n-1);
                    break;
                }
                case 2: {
                    long long one_cnt = sg.calculation();
                    sum = (1ll*one_cnt*query[1])+sum;
                    break;
                }
                case 3: {
                    res.push_back(sum);
                    break;
                }
            }
        }

        return res;
    }
};
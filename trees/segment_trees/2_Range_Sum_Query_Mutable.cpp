// Question Link - https://leetcode.com/problems/range-sum-query-mutable/description/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

class NumArray {
public:
    int seg[100500]={0};
    vector<int> arr;

    void buildTree(int idx, int l, int r) {
        if(l==r) {
            seg[idx]=arr[l];
            return;
        }

        int mid = (l+r)/2;
        buildTree(2*idx+1, l, mid);
        buildTree(2*idx+2, mid+1, r);
        seg[idx] = seg[2*idx+1]+seg[2*idx+2];
    }

    void update(int idx, int l, int r, int update_idx, int update_val) {
        if(l==r && l==update_idx) {
            seg[idx]=update_val; return;
        }

        int mid = (l+r)/2;
        if(update_idx<=mid) update(2*idx+1, l, mid, update_idx, update_val);
        else update(2*idx+2, mid+1, r, update_idx, update_val);
        seg[idx] = seg[2*idx+1]+seg[2*idx+2];
    }

    int cal(int idx, int l, int r, int start, int end) {
        if(l>end || r<start) return 0;
        else if(l>=start && r<=end) return seg[idx];
        else {
            int mid = (l+r)/2;
            int x = cal(2*idx+1, l, mid, start, end);
            int y = cal(2*idx+2, mid+1, r, start, end);
            return x+y;
        }
    }

    NumArray(vector<int>& nums) {
        arr = nums;
        buildTree(0, 0, arr.size()-1);
    }
    
    void update(int index, int val) {
        update(0, 0, arr.size()-1, index, val);
    }
    
    int sumRange(int left, int right) {
        return cal(0, 0, arr.size()-1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
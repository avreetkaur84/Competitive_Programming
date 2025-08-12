// Question Link - https://leetcode.com/problems/maximum-k-to-sort-a-permutation/description/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

/*
Key Lesons -
    Bitwise AND property:
    For a bit to remain 1 in AND across multiple numbers, it must be 1 in all of them.
    If any number has that bit 0, the result at that position will be 0.

    "Requirement collection" approach:
    Instead of building a number from scratch, sometimes you should ask:
    “What’s the minimum requirement that satisfies all conditions?”
    → Here, the requirement was that all 1 bits from all numbers must be in k.

    Think bit-by-bit instead of whole number:
    In binary problems, analyzing each bit position independently is often simpler than thinking of the number as a whole.
    This breaks the problem into 32 or 64 tiny problems.

    Translate “weird” constraints into familiar rules:
    “x & k == x” → “all 1 bits of x are also 1 in k.”
    That rephrasing is the step that unlocks the solution.
*/

class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int res=-1;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i]!=i) {
                if(res==-1) res=nums[i];
                else res = res & nums[i];
            }
        }

        return res==-1 ? 0 : res;
    }
};
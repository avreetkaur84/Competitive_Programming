// Question Link - https://leetcode.com/problems/subsets/description/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

// This is really an interesting problem. 
/*
    0 - 000
    1 - 001
    2 - 010 
    and so on till 2^n are the total number of subsets a power set will have.
    So, here, mask is the number 0, 1, 2 which is first for loop and i is the binary bits which is the second for loop.
    Now, a number is added in subset if the ith bit is set in the binary form of the mask, which is number. 
*/

vector<vector<int>> subsets(vector<int> &nums)
{
    vector<vector<int>> res;
    int n = nums.size();
    for (int mask = 0; mask < (1 << n); mask++)
    {
        vector<int> arr;
        for (int i = 0; i < n; i++)
        {
            if (mask & (1 << i))
            {
                arr.push_back(nums[i]);
            }
        }
        res.push_back(arr);
    }

    return res;
}
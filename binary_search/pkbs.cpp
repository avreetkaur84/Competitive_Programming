#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {

        // step 1] search the half sorted part

        int s = 0;
        int e = nums.size() - 1;
        while (s <= e)
        {
            int mid = s + (e - s) / 2;

            // agar target mid pe hee mil gya
            if (nums[mid] == target)
                return mid;

            // yaa to left part sorted hoga
            if (nums[s] <= nums[mid])
            {
                // agar target hai left part kme
                if (nums[s] <= target && target <= nums[mid])
                {
                    // e kpo left me lao
                    e = mid - 1;
                }
                else
                {
                    // agar target hai hee nhi hai left part me

                    // to s ko right part  me shift kar do
                    s = mid + 1;
                }
            }
            // yaa o right part sorted hoga
            else
            {
                // agr target hai right part me
                if (nums[mid] <= target && target <= nums[e])
                {
                    // s ko right part me shift kar do
                    s = mid + 1;
                }
                else
                {
                    // agar target hua hee nhi right part me

                    // e ko right part me shift kar do
                    e = mid - 1;
                }
            }
        }
        return -1;
    }
};
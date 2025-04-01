// SOLUTION 3 - KADANE'S ALGO

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> nums;
    int sum=0; int maxx=INT_MIN, n=nums.size();
    int idx = 0, startIdx = 0, endIdx = 0;
    for (int i = 0; i < n; i++)
    {
        sum += nums[i];
        // maxx=max(sum, maxx);
        if (sum > maxx)
        {
            maxx = sum;
            // startIdx=idx; endIdx=i+1;
        }

        if (sum <= 0)
        {
            sum = 0;
            idx = i;
        }
    }

// for(int i=startIdx; i<endIdx; i++) cout<<nums[i]<<"   ";

return maxx;
}

// Question Link - https://www.naukri.com/code360/problems/painter-s-partition-problem_1089557?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int paintersNum(vector<int> &boards, int x) {
    long long sum=0; int cnt=0;
    for(int i=0; i<boards.size(); i++) {
        if(sum+boards[i]<=x) sum+=boards[i];
        else {
            cnt++; sum=boards[i];
        }
    }

    cnt++; return cnt;
}

int findLargestMinDistance(vector<int> &boards, int k)
{
    long long prefixSum = 0;
    for(int &x : boards)   prefixSum+=x;

    long long low = *max_element(boards.begin(), boards.end());
    long long high=prefixSum, mid;

    while(low<=high) {
        mid = low+(high-low)/2;

        int num = paintersNum(boards, mid);
        if(num>k)  low=mid+1;
        else high=mid-1;
    }

    return low;
}
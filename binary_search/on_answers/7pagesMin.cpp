// Question Link - https://www.naukri.com/code360/problems/allocate-books_1090540?utm_source=youtube&utm_medium=affiliate&utm_campaign=codestudio_Striver_BinarySeries&leftPanelTabValue=PROBLEM

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int pagesSum(vector<int> arr, int mid) {
    int j=0, cnt=0;
    long long sum=0;

    for(int j=0; j<arr.size(); j++) {
        if(sum+arr[j]<=mid) {
            sum+=arr[j];
        } else {
            // if(sum>min_sum) min_sum=sum;
            cnt++; sum=arr[j];
        }
    }
    
    cnt++;
    return cnt;
}

int findPages(vector<int>& arr, int n, int m) {
    // sort(arr.begin(), arr.end());

    if(m>n) return -1;
    int pSum=0;
    for(int i=0; i<arr.size(); i++)   pSum+=arr[i];

    // cout<<"Found"<<endl;

    int low=*max_element(arr.begin(), arr.end()); 
    int high=pSum, mid;

    while(low<=high) {
        mid = low+(high-low)/2;

        int cnt = pagesSum(arr, mid);

        if(cnt>m)   low=mid+1;
        else high=mid-1;
    }

    return low;
}
// Question Link - https://www.geeksforgeeks.org/problems/find-nth-root-of-m5843/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=find-nth-root-of-m

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int nthRoot(int n, int m) {
    long low=1, high=m, mid;
    
    while(low<=high) {
        mid=low+(high-low)/2;
        // cout<<"mid: "<<mid<<endl;
        
        if(pow(mid, n)==m)  return mid;
        else if(pow(mid,n)<m && pow(mid+1, n)>m )   return -1;
        
        // cout<<pow(mid, n)<<endl;
        
        if(pow(mid, n)<m)   low=mid+1;
        else high=mid-1;
    }
}
// Question Link - https://www.naukri.com/code360/problems/subset-sum_630213?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void print(vector<int> arr) {
    cout<<endl;
    for(auto &x : arr)  cout<<x<<"  ";
    cout<<endl;
}

void sequenceCheck(int n, int k, vector<int> arr, vector<int> op, int &cnt) {
    if(arr.size()==0) {
        int sum = accumulate(op.begin(), op.end(), 0);
        // print(op); 
        // cout<<sum<<"    ";
        // cout<<cnt<<"    ";
        if(sum==k)  {
            cnt++;
            // print(op);
        }
        return;
    }

    vector<int> Nonpick = op;
    op.push_back(arr[0]);
    vector<int> pick = op;

    if(!arr.empty()) arr.erase(arr.begin());
    sequenceCheck(n, k, arr, Nonpick, cnt);
    sequenceCheck(n, k, arr, pick, cnt);
}

bool isSubsetPresent(int n, int k, vector<int> &a)
{
    vector<int> res; int cnt=0;
    sequenceCheck(n, k, a, res, cnt);

    if(cnt==0)   return false;
    else true;
}
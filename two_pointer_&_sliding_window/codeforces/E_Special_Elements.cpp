// Question Link - https://codeforces.com/contest/1352/problem/E

#include <bits/stdc++.h>
#define ll long long
using namespace std;

void inArr(vector<int> &arr, int n) {
    for(int i=0; i<n; i++) cin>>arr[i];
}

void outArr(vector<int> &arr) {
    for(int i=0; i<arr.size(); i++) cout<<arr[i]<<" ";
    cout<<"\n";
}

bool checker(vector<int> arr, int x) {
    int n=arr.size(), i=x-1, j=x+1, i_sum=0, j_sum=0;
    if(x-1<=0) i=-1;
    if(x+1>=n-1) j=n;

    int ie=i;
    // cout<<"i: \n";
    while(i>=0) {
        // cout<<i<<" "<<i_sum<<"\n";
        i_sum+=arr[i];
        while(i_sum>arr[x] && ie>i) {
            i_sum-=arr[ie]; ie--;
        }
        // ie-i -> need min 2 elements
        if(i_sum==arr[x] && ie-i>0) return true;
        i--;
    }

    int je=j;
    // cout<<"j: \n";
    while(j<n) {
        // cout<<j<<" "<<j_sum<<"\n";
        j_sum+=arr[j];
        while(j_sum>arr[x] && je<j) {
            j_sum-=arr[je]; je++;
        }
        if(j_sum==arr[x] && j-je>0) return true;
        j++;
    }
    // cout<<"\n";

    return false;
}

void solve() {
    int n;  cin>>n;
    vector<int> arr(n); inArr(arr, n);
    // outArr(arr);
    int cnt=0;

    for(int i=0; i<n; i++) {
        bool flag = checker(arr, i);
        if(flag) {
            cnt++; 
            // cout<<arr[i]<<" ";
        }
        // cout<<"\n";
    }

    cout<<cnt<<endl;
}



int main()
{
    int t;
    cin >> t;

    
    while(t--)
    {
        solve();
    }
}
// Question Link - 

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int cowsFit(vector<int> arr, int x) {
    int i=0, j=1, cnt=0;
    while(j<arr.size()) {
        if(arr[j]-arr[i]>=x) {
            cnt++;  i=j; j=i+1;
        } else {
            j++;
        }
    }
    
    cnt++;
    return cnt;
}

void solve() {
    int n, c; cin>>n>>c;
    vector<int> arr(n);
    for(int &x: arr)    cin>>x;

    sort(arr.begin(), arr.end());
    int low=1, high=arr[arr.size()-1]-arr[0], mid;
    // cout<<"Sorted"<<endl;
    
    while(low<=high) {
        mid = low+(high-low)/2;

        // cout<<"Function called"<<endl;
        int cows = cowsFit(arr, mid);

        // cout<<"low:"<<low<<",   high:"<<high<<",    mid:"<<mid<<",    cows:"<<cows<<endl;
        if(cows>=c)  low=mid+1;
        else high=mid-1;
    }

    cout<<high<<endl;  
    
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
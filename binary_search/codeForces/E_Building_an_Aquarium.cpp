// Question Link - https://codeforces.com/problemset/problem/1873/E

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

long long water(vector<int> arr, int h) {
    long long sum = 0;
    // cout<<"H:"<<h<<" "<<"Sum: ";
    for(int i=0; i<arr.size(); i++) {
        if(arr[i]<h)    sum+=h-arr[i];
        // cout<<sum<<"    ";
    }
    // cout<<endl;
    return sum;
}

void solve() {
    int n, x; cin>>n>>x;
    vector<int> arr(n);
    for(int &x : arr)   cin>>x;

    // find h -> to fill water -> max units
    // h vary -> range
    // water contraint, 

    int low = *min_element(arr.begin(), arr.end());
    int high = *max_element(arr.begin(), arr.end())+x;
    int mid;

    while(low<=high) {
        mid = low+(high-low)/2;

        long long w = water(arr, mid);
        // cout<<"low:"<<low<<"    mid:"<<mid<<"   high:"<<high<<"   w:"<<w<<endl;

        if(w>x) high=mid-1;
        else low=mid+1;
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
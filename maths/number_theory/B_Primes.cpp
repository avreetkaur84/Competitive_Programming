// Question Link - https://codeforces.com/problemset/gymProblem/102267/B

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

// find all prime numbers in the range

void sieveAlgo(vector<bool> &arr, int n) {
    arr[0]=false;   arr[1]=false;
    for(int i=2; i*i<=n; i++) {
        if(arr[i]) {
            for(int j=i*i; j<=n; j+=i) {
                arr[j]=false;
            }
        }
    }
}

void solve() {
    int sum; cin>>sum;
    vector<bool> arr(sum+1, true);
    sieveAlgo(arr, sum);
    // cout<<"entered"<<endl;

    for(int i=2; i<arr.size(); i++) {
        if(arr[i]==true && arr[sum-i]==true) {
            cout<<i<<" "<<sum-i<<endl;  return;
        }
    }

    cout<<-1<<endl; return;
}



int main()
{
    // int t;
    // cin >> t;
    
    // while(t--)
    // {
    //     solve();
    // }
    solve();
}
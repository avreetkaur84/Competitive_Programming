// Question Link - https://codeforces.com/problemset/problem/1883/C

#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    int n, k;  cin>>n>>k;
    vector<int> arr(n);
    bool flag=false; int minn=INT_MAX; int f_cnt=0;

    for(int i=0; i<n; i++) {
        cin>>arr[i];

        if(arr[i]%k==0) flag=true;
        else {
            if(k==4) {
                if(arr[i]%2==0 && f_cnt<2)  f_cnt++;
            } 

            int rem = arr[i]/k;
            int diff = k*(rem+1)-arr[i];
            minn = min(diff, minn);
        }
    }

    if(flag==true)  cout<<0<<endl;
    else if(k==4) cout<<min(2-f_cnt, minn)<<endl;
    else    cout<<minn<<endl;
    

    // cout<<cnt<<endl;
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
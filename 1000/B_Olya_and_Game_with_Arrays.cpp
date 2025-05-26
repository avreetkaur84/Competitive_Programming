// Question Link - 

#include <bits/stdc++.h>
#define ll long long
using namespace std;

// I have to add all the second min elements, then substract the min of second min and add min of first min.

void solve() {
    int n;  cin>>n; 
    int f_min=INT_MAX, s_min=INT_MAX; ll sum=0;
    
    while(n--) {
        int m;  cin>>m;
        vector<int> arr(m);
        for(int i=0; i<m; i++) cin>>arr[i];

        sort(arr.begin(), arr.end());
        f_min = min(f_min, arr[0]);
        s_min = min(s_min, arr[1]);
        sum+=arr[1];
    }

    ll beauty = sum+f_min-s_min;

    cout<<beauty<<endl;    
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


// First try
    // way too complex
    // while(n--) {
    //     int m;  cin>>m;
    //     vector<int> arr(m); 
    //     int f_minn=INT_MAX;
    //     for(int i=0; i<m; i++) {
    //         cin>>arr[i];  f_minn=min(f_minn, arr[i]);
    //     }

    //     int s_minn=INT_MAX; int cnt=0;
    //     for(int i=0; i<m; i++) {
    //         if(arr[i]!=f_minn) s_minn=min(s_minn, arr[i]);
    //         else {
    //             cnt++;
    //             if(cnt>1) s_minn=min(s_minn, arr[i]);
    //         }
    //     }

    //     s[g]=s_minn;    f[g]=f_minn;    g++;
    // }
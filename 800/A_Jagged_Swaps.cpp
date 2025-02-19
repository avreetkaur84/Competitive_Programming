// Question Link - 

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
 questions of range 800 are more about observation rather than coding and logic.
 To exemplify - in this question - I applied the logic of calculating frequencies, then swaping and stuff, but it was not that complex in first place.
 They have given in question that array contains numbers from 1 to n, and we can't swap the first number.
 So, it is clear that, if first no is 1 than array can be sorted else, it is not.

 Although it doesn't cover up edge cases, but observation is something that beginer like me miss, and focus on complex logic building.
*/

void solve() {
    int n; cin>>n;
    vector<int> arr(n); vector<int> freq(n+1);

    // observation logic
    for(int &x : arr)   cin>>x;

    if(arr[0]==1)   cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

    
    // for(int i=0; i<n; i++) {
    //     cin>>arr[i];
    //     if(arr[i]>n) {
    //         cout<<"NO"<<endl;   return;
    //     }

    //     if(freq[arr[i]]==0) freq[arr[i]]++;
    //     else {
    //         cout<<"NO"<<endl;   return;
    //     }
    // }

    // for(int i=1; i<n-1; i++) {
    //     if(arr[i-1]<arr[i] && arr[i+1]<arr[i]) {
    //         int temp = arr[i];
    //         arr[i] = arr[i+1];
    //         arr[i+1] = temp;
    //     }
    // }

    // if(is_sorted(arr.begin(), arr.end()))   cout<<"YES"<<endl;
    // else cout<<"NO"<<endl;
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


// very first try 
// void solve() {
//     int n; cin>>n;
//     vector<int> arr(n);
//     set<int> st;    
//     for(int i=0; i<n; i++)  cin>>arr[i];

//     st.insert(arr[0]);

//     // if(is_sorted(arr.begin(), arr.end()))   cout<<"NO"<<endl;

//     for(int i=1; i<n-1; i++) {
//         if(arr[i]>n)    cout<<"NO"<<endl;

//         if(st.find(arr[i]) != st.end()) cout<<"NO"<<endl;

//         if(arr[i-1]<arr[i] || arr[i]>arr[i+1]) {
//             int temp = arr[i];
//             arr[i] = arr[i+1];
//             arr[i+1] = arr[i];
//         }
//     }

//     if(is_sorted(arr.begin(), arr.end()))   cout<<"YES"<<endl;
//     else cout<<"NO"<<endl;
// }
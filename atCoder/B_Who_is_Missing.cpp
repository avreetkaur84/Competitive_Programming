// Question Link - 

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, M; cin>>N>>M;
    // vector<int> arr(M);
    set<int> st;
    
    for(int i=0; i<M; i++)  {
        int num; cin>>num;
        st.insert(num);
    }

    int total = N - st.size();
    cout<<total<<endl;

    for(int i=1; i<=N; i++) {
        if(st.find(i)!=st.end()) {
            continue;
        } else cout<<i<<" ";
    }

    // sort(arr.begin(), arr.end());
    // if(arr[M-1]!=N) arr.push_back(N);

//     int j=0;

//    int i=1;
//    for(int j=0; j<arr.size(); j++){
//         while(i!=arr[j]) {
//             cout<<i<<" ";
//             i++;
//         }
//     }  

}


int main()
{
    solve();
}
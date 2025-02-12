// Question Link - 

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin>>n;
    vector<int> even;
    //  vector<int> arr(n);
    set<int> st;
    for(int i=0; i<n; i++) {
        int num; cin>>num;
        st.insert(num);
        if(num%2==0)    even.push_back(num);
        // else odd.push_back(num);
    }
    
    sort(even.begin(), even.end());
    
    if(st.find(even[0]) != st.end() && 
        st.find(even[(even.size()-1)/2]) != st.end() &&
        st.find((even[0]+even[even.size()-1])/2) != st.end()) {
            cout<<-1<<endl;
        }
    else {
        cout<<2<<endl;
        cout<<even[0]<<" "<<even[even.size()-1]<<endl;
    }

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



// #include <bits/stdc++.h>
// using namespace std;

// typedef long long ll;

// void solve() {
//     int N;
//     cin >> N;
//     vector<int> A(N);
//     unordered_map<int, int> freq;
    
//     for (int i = 0; i < N; i++) {
//         cin >> A[i];
//         freq[A[i]]++;
//     }
    
//     for (auto &p : freq) {
//         if (p.second > 1) {
//             cout << "1\n" << p.first << "\n";
//             return;
//         }
//     }
    
//     cout << "-1\n";
// }

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
    
//     int T;
//     cin >> T;
//     while (T--) {
//         solve();
//     }
    
//     return 0;
// }
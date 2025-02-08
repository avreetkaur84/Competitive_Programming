// Question Link - 

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N; cin>>N;
    vector<int> P(N); 
    vector<pair<int, int>> res(N+1);
    vector<int> l(N+1);
    // map<int, int> mp;
    
    // for(int i=0; i<N; i++)  cin>>P[i];
    for(int i=1; i<N+1; i++)  {
        int n; cin>>n;
        res.push_back({n, P[i]});
        // res.insert(res.begin()+n, {i, P[i]});
    }

    int i=0;
    while(i<N) {
        int bib_no = res[i].first;
        int stare = res[i].second;
        int final_bib = res[stare].first;
        l[bib_no] = final_bib;
    }
    
    // for(int i=1; i<=N; i++) {
    //     int stare = res[i].second;

    // }

    for(int i=1; i<=N; i++) cout<<l[i];

}

int main()
{
    solve();
}
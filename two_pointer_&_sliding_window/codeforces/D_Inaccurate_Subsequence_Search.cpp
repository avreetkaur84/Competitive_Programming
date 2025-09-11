// Question Link - 

#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD = 1000000007;

/*    
    a b c
    c -> good : has m (len) -> k matches b
    task: a -> m(len) : contains good arrays
    - Simple sliding window problem of freq count.
    - As we can reorder the b array elements, so what matters is freq.
*/

void inArr(vector<int> &arr, int n) {
    for(int i=0; i<n; i++) cin>>arr[i];
}

void outArr(vector<int> &arr) {
    for(int i=0; i<arr.size(); i++) cout<<arr[i]<<" ";
    cout<<"\n";
}

void solve() {
    int n, m, k;  cin>>n>>m>>k;
    vector<int> a(n); inArr(a, n);
    vector<int> b(m); inArr(b, m);
    
    unordered_map<int, int> b_mp;
    for(int i=0; i<m; i++) b_mp[b[i]]++;    

    unordered_map<int, int> a_mp; int t_ele=0;
    for(int i=0; i<m; i++) {
        a_mp[a[i]]++;
    }

    for(auto it : b_mp) {
        if(a_mp.find(it.first)!=a_mp.end()) {
            t_ele+=min(a_mp[it.first], it.second);
            // cout<<it.first<<" "<<it.second<<" "<<t_ele<<"\n";
        }
    }

    ll cnt=0; int i=0, j=m-1;
    if(t_ele>=k) cnt++;
    // cout<<cnt<<"\n";
    // cout<<i<<" "<<j<<" "<<cnt<<" "<<t_ele<<"\n";

    j++;
    while(j<n) {
        a_mp[a[i]]--; 
        if(b_mp.find(a[i])!=b_mp.end() && a_mp[a[i]]<b_mp[a[i]]) t_ele--;
        i++;
        
        a_mp[a[j]]++;  
        // cout<<"#"<<a[j]<<" "<<a_mp[a[j]]<<" "<<b_mp[a[j]]<<" "<<"\n";
        if(b_mp.find(a[j])!=b_mp.end() && a_mp[a[j]]<=b_mp[a[j]]) t_ele++;

        if(t_ele>=k) cnt++;

        // cout<<i<<" "<<j<<" "<<cnt<<" "<<t_ele<<"\n";
        j++;        
    }

    cout<<cnt<<"\n";
    // cout<<"\n";
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
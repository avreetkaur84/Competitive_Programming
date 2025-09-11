// Question Link - 

#include <bits/stdc++.h>
#define ll long long
using namespace std;

/*
    My mistake: I assumed if sum > s, Bob can rearrange.
    Editorial: It’s actually d = s - base_sum, and d = 1 is the special case.
*/

void display(vector<int> arr) {
    for(int i=0; i<arr.size(); i++)  cout<<arr[i]<<" ";
    cout<<endl;
}

void solve() {
    int n, s;  cin>>n>>s;
    vector<int> arr(n); int sum=0; 
    int o_cnt=0, two_cnt=0;
    for(int i=0; i<n; i++) {
        cin>>arr[i]; sum+=arr[i];
        if(arr[i]==0) o_cnt++; if(arr[i]==2) two_cnt++;
    }

    // required sum (s) = base_sum + x 
    int x = s-sum;

    if(sum==s) cout<<-1<<endl;
    else if(sum>s) display(arr);
    else {
        if(x==1) {
            int i=0;
            while(i<n) {
                if(o_cnt>0) {
                    cout<<0<<" "; o_cnt--;
                }
                else if(two_cnt>0) {
                    cout<<2<<" "; two_cnt--;
                } else {
                    cout<<1<<" ";
                }
                i++;
            }
            cout<<endl;
        } else {
            cout<<-1<<endl;
        }
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
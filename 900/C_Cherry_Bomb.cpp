// Question Link - 

#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    int n;  cin>>n;
    ll k;   cin>>k;
    vector<int> a(n);   vector<int> b(n);
    ll sum=0; bool flag=false;

    for(int i=0; i<n; i++) cin>>a[i];

    for(int i=0; i<n; i++) {
        cin>>b[i];
        if(b[i]!=-1) {
            sum=b[i]+a[i];
            flag=true;
        }   
    }

    if(flag==false) {
        int m = *max_element(a.begin(), a.end());
        int n = *min_element(a.begin(), a.end());

        int res = (n+k)-m+1;
        cout<<res<<endl;    return;
    }

    // check for complimentary
    for(int i=0; i<n; i++) {
        if( (b[i]!=-1 && (b[i]+a[i])!=sum) || 
            (a[i]>sum) || 
            (b[i]==-1 && (a[i]+k)<sum)
        )  {
            cout<<0<<endl;  return;
        }
    }

    cout<<1<<endl;
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
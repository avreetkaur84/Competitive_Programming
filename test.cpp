#include <bits/stdc++.h>
#define for0(i,n) for(int i=0;i<n;i++)
#define forr(i, n) for (int i = n - 1; i >= 0; i--)
#define for1(i,n) for(int i=1;i<=n;i++)
#define forab(j,a,b) for(j=a;j<=b;j++)
#define tc(t) int t;cin >>t;while(t--)
//#define int  long long
#define ll long long 
#define pb(ans,i) ans.push_back(i)
#define pbpp(vec, k, i) vec.push_back({k, i})
#define v(a, n) vector<int> a(n); for(int i = 0; i < n; i++) cin >> a[i];
#define sortall(v) sort(v.begin(), v.end())
#define vpp(a) vector<pair<ll, ll>> a;
#define cinNK(n, k) int n, k; cin >> n >> k;
#define cinAB(a) int a; cin >> a;
#define cinAB2(a, b) int a, b; cin >> a >> b;
#define cinAB3(a, b, c) int a, b, c; cin >> a >> b >> c;
#define cinAB4(a, b, c, d) int a, b, c, d; cin >> a >> b >> c >> d;
using namespace std;
 
void ArrIsPoss(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int>b(n-2); for(int i=0; i<n-2; i++) cin>>b[i];

        if(n==3){
            cout<<"YES"<<endl;
            continue;
        }

        bool arrISPoss=true;
        for(int i=0; i<n-2; i++){
            if(i+2<b.size() && b[i]==1 && b[i+1]==0 && b[i+2]==1){
                arrISPoss=false;
                break;
            }
        }
        
        if(arrISPoss) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}
void cpguy12433(){
    ArrIsPoss();
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cpguy12433(); 
    return 0;
}
// Question Link - 

#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD = 1000000007;

/*
    arr -> insert a[i] -> distinct
    make arr equal -> add same x to all
    smallest operations ->
    - if all numbers have same remainder when mod by x -> then we can convert all numbers to each other. 
    - to get the largest x, just take gcd of pairwise difference of array elements. Property!!
*/
int mod(int a, int m) {
    int r = a % m;
    if (r < 0) r += m;  
    return r;
}

void inArr(vector<int> &arr, int n) {
    for(int i=0; i<n; i++) cin>>arr[i];
}

void outArr(vector<int> &arr) {
    for(int i=0; i<arr.size(); i++) cout<<arr[i]<<" ";
    cout<<"\n";
}

void outArr2d(vector<vector<int>> arr) {
    for(int i=0; i<arr.size(); i++) {
        for(int j=0; j<arr[i].size(); j++) {
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";
}

void solve() {
    int n;  cin>>n;
    vector<int> arr(n); inArr(arr, n);
    sort(arr.begin(), arr.end(), [](int a, int b) {
        return a>b;
    });
    // outArr(arr);

    if(n==1) {
        cout<<1<<"\n"; return;
    }

    int mx = arr[0];
    ll op=0;

    // esmein optimise -> property used
    int mn = arr[n-1], x=0;
    for(int i=0; i<n; i++) {
        x = __gcd(abs(arr[i]-mn), x);
    }
    // cout<<x<<" ";
    x = (x==0) ? 1 : x;


    for(int i=1; i<n; i++) {        
        op += (mx-arr[i])/x;   // op cal for nomal arr[i]
    }
    
    int last=0;  int j=1;
    for(int i=1; i<n; i++) {
        // inserting element: multiple of x
        if(arr[i]!=mx-(j*x)) {
            // last = mx-(j*x);
            break;
        }
        j++;
    }

    // cout<<last<<" ";
    last = mx-(j*x);
    op += (mx-last)/x;
    cout<<op<<"\n";
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
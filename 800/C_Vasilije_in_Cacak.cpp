// Question Link -

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve()
{
    ll n, k, x;
    cin >> n >> k >> x;

    ll min_sum = (k * (k + 1)) / 2;
    ll max_sum = (n - k + 1 + n)*k/2;
    // max sum formula is derved from teh arithmetic or continuos seres formula->sum = (total_terms / 2) * (first_term + last_term)

    // sum of n numbers
    // sum = (k * (k + 1)) / 2;
    
    // cout<<"min sum: "<<min_sum<<"   max_sum: "<<max_sum<<"  ";

    if (min_sum<=x && x<=max_sum)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }
}

// if(min_sum>=x || x>=max_sum) {
//     cout<<"NO"<<endl;  return;
// }
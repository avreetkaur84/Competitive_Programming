// Question Link - 

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    int n;  cin>>n;

    if(n%2==0)   {
        cout<<-1<<endl;
        return;
    }

    cout<<n<<" ";

    for(int i=2; i<=n; i++) {
        cout<<i-1<<" ";
    }

    cout<<endl;
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
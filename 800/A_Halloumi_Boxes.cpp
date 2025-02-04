#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        // if(k==n)    cout<<"YES"<<endl;
        // else if(is_sorted(a.begin(), a.end()))   cout<<"YES"<<endl;


        if(!is_sorted(a.begin(), a.end()) && k==1) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
}
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    for (int x = t; x > 0; x--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        // MY APPROACH - USED 2 VARIABLES
        // if(a.size()==k) {
        //     int i=1; int j=1;
        //     while(a[j]==i) {
        //         j+=2; i++;
        //     }
        //     cout<<i<<endl;
        // }

        // OPTIMZED APPROACH WITH ONE VARIABLE
        if (a.size() == k)
        {
            for (int i = 1; i < n; i += 2)
            {
                if (a[i] != (i + 1) / 2)
                {
                    cout << (i + 1) / 2 << endl;
                }
            }
            cout<<(k/2)+1<<endl;
        }

        // else if (a.size() == k + 1)
        // {
        //     if (a[1] != 1 || a[2] != 1)
        //         cout << 1 << endl;
        //     else if ((a[1] == 1 || a[2] == 1))
        //         cout << 2 << endl;
        // }

        // till last starting point subarray could start
        else {
            bool found = false;
            for(int i=1; i<=n-k+1; i++) {
                if(a[i]!=1) {
                    cout<<1<<endl;
                    found = true;
                    break;
                }
            }
            if(!found) cout<<2<<endl;
        }
    }
}
// Question Link - https://codeforces.com/problemset/problem/1890/A

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Two Elements with same frequency
// size cant exceed 3

// we can't use array to calculate frequency as a[i] limit is 10^5. So, it is inefficient.
// we can't use set, as set will only tell us no. of elements, but we need to have freq also.

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    map<int, int> freq;
    // vector<int> freq(n);
    // set<int> st;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        freq[arr[i]]++;
    }

    if (freq.size() >= 3)
        cout << "No" << endl;
    else
    {
        if ((abs(freq.begin()->second - freq.rbegin()->second)) <= 1)
        {
            cout << "Yes" << endl;
        }
        else
            cout << "No" << endl;
    }
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
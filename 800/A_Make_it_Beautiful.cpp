// Question Link - https://codeforces.com/problemset/problem/1783/A

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    int sum_check = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    if(arr[0]==arr[n-1]) {
        cout<<"NO"<<endl; return;
    }

    if(n>2) {
        swap(arr[n-1], arr[1]);
        swap(arr[1], arr[0]);
    }

    // sort(arr.begin(), arr.end(), greater<int>());

    cout << "YES" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
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
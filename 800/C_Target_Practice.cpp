// Question Link - https://codeforces.com/problemset/problem/1873/C

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void solve() {
    char grid[10][10]; 
    int score=0;
    for(int i=0; i<10; i++) {
        for(int j=0; j<10; j++) {
            cin>>grid[i][j];
            if(grid[i][j]=='X') {
                // didn't take i into consideration
                // if(j>4) score+=(10-j);
                // else score+=j+1;

                score += min({i, j, 9 - i, 9 - j}) + 1;
            }
        }
    }

    cout<<score<<endl;
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
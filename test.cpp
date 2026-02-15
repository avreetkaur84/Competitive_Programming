// Question Link - 

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

/*
    There is a special sqaure room with mirrors, 
    teher are receoptorrs for eahc fo teh remaning columns, number 0,1,2. Square room has walls of lenghth p and laser lay from south west corner, first meet the east wall at distance q form teh zero receptor. Givne two intergers p and q, 

    solved using lcm , number theory
    1661 D
*/

int main() {
    int i=2, n=15; 
    int x = (n & ~(1<<i));
    cout<<x<<"\n";
}
// Question Link - 
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*
        two lanes -> x & y -> Alice and bob
        range: x->n & y->m : Alice win game
        Goal: 
            -Alice should capture the last flower, alice will start and alice should finish. So, we have to output possible no of flowers x and y can have, so that alice wins
        Solution:
            - Alice start & end: so, one row will have even flowers and other row will have odd
            - Calculate all the possible permutations of even and odd. Order won't matter: (2,3) and (3,2)  will be different pairs
        Barrier: 
            - How to count the total even and odd pairs in range.
            - 
    */

    long long flowerGame(int n, int m) {
        long long x_e=n/2, y_e=m/2, x_o=(n+1)/2, y_o=(m+1)/2; 
        // cout<<x<<" "<<y<<" ";
        return (x_e*y_o)+(x_o*y_e);
    }
};
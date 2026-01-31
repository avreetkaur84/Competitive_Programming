#include <bits/stdc++.h>
using namespace std;

// wrong answer is coming
int main() {
    int a1, a2, b1, b2, c1, c2;
    cin>>a1>>b1>>c1;
    cin>>a2>>b2>>c2;

    int d = (a1*b2)-(a2*b1);
    if(d==0) return -1;   // no solution

    int x = (b1*c2)-(b2*c1);
    x = x/d;

    int y = (a1*c2)-(a2*c1);
    y = y/d;

    cout<<"Line intersecting points are: ";
    cout<<x<<" "<<y<<"\n";
}
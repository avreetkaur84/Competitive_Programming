// Question Link - 

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    int x, y, z, a, b, c;
    cin>>x>>y>>z>>a>>b>>c;

    int cnt=0;
    int z_ext=0, y_ext=0;

    if(z>=c) {
        cnt += c;
        z_ext = z-c;
    } else {
        cnt += z;
    }

    if(y>=b) {
        cnt += b;
        y_ext = y-b;
    } else {
        cnt += y;
        if(z_ext>0) {
            int t_req = b-y;
            if(z_ext>=t_req) {
                cnt+=t_req;
                z_ext-=t_req;
            } else {
                cnt+=z_ext;
                z_ext=0;
            }
        }
    }

    if(x>=a) {
        cnt += a;
        // y_ext = y-b;
    } else {
        cnt += x;
        int t_req = a-x;

        if(z_ext>0) {
            if(z_ext>=t_req) {
                cnt+=t_req;
                z_ext-=t_req;
                t_req=0;
            } else {
                cnt+=z_ext;
                t_req-=z_ext;
                z_ext=0;
            }
        }

        if(y_ext>0) {
            if(y_ext>=t_req) {
                cnt+=t_req;
                y_ext-=t_req;
            } else {
                cnt+=y_ext;
                t_req-=y_ext;
                y_ext=0;
            }
        }
    }

    cout<<cnt<<endl;
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
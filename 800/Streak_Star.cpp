#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, X, max=0; 
    cin>>N>>X;
    bool flag=false;

    vector<int> arr(N);
    for(int i=0; i<N; i++)  cin>>arr[i];
    int m=0, n=1;

    while(n<arr.size()) {
        if(arr[n-1]<arr[n])   n++;
        else {
            if(!flag)  {
                arr[n] = arr[n]*X;
                if(arr[n-1]<arr[n]*X) {
                    flag=true;
                    // n++; break;
                } 
            }

            if(arr[n-1]<arr[n] && (n<arr.size()-1))   {
                n++;
            }
            else {
                if((n-m)>max) {
                    if(n==arr.size()-1) {
                        max=n-m+1;
                    } else {
                        max=n-m;
                    }
                    
                    // cout<<max<<endl;
                }
                m=n; n++;
            }
        }
    }
    cout<<max<<endl;
}

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        // cout<<"t"<<t<<endl;
        solve();
    }
}
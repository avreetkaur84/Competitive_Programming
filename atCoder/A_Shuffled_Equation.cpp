// Question Link - 

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void solve() {
    vector<int> arr(3);
    int max=0, j=0;
    for(int i=0; i<3; i++)  {
        cin>>arr[i];
       if(max<arr[i]) {
        max=arr[i];
        j=i;
        // cout<<max<<endl;
       }
    }

    // cout<<arr[0]<<" "<<arr[1]<<endl;
    arr[j]=1;

    if((arr[0]*arr[1]*arr[2])==max) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;

}

int main()
{
    solve();
}
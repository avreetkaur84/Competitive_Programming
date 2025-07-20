// Question Link - 

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

// void printPrimes(vector<bool> arr) {
//     int n = arr.size();
//     for(int i=0; i<n; i++) {
//         if(arr[i])  cout<<i<<" ";
//     }
// }

// will get range of prime no
void sieveAlgo(vector<bool> &arr, int n) {
    arr[0]=false; arr[1]=false;
    for(int i=2; i*i<=n; i++) {
        if(arr[i]) {
            for(int j=i*i; j<n; j+=i) {
                arr[j]=false;
            }
        }
    }
}


// check if almost prime or not
int check(vector<bool> arr, int n) {
    int cnt=0;
    for(int i=2; i<n; i++) {
        if(arr[i]==true && n%i==0) cnt++;
    }

    if(cnt==2)  return 1;
    else return 0;
}

// count no. of almost prime
int countNo(vector<bool> arr, int n) {
    int cnt=0;
    for(int i=2; i<=n; i++) {
        int res = check(arr, i);
        // cout<<i<<" "<<res<<"   ";
        cnt += res;
    }

    return cnt;
}


int main()
{
    int n;  cin>>n;
    vector<bool> arr(n+1, true);
    sieveAlgo(arr, n+1);
    // printPrimes(arr);
    cout<<countNo(arr, n)<<endl;
}
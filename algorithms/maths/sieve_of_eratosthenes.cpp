// this algorithm if used for finidng the prime numbers in a range.
// Program Link - https://cp-algorithms.com/algebra/sieve-of-eratosthenes.html

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void printPrimes(vector<bool> arr) {
    int n = arr.size();
    for(int i=0; i<n; i++) {
        if(arr[i])  cout<<i<<" ";
    }
}

void sieveAlgo(vector<bool> &arr, int n) {
    arr[0]=false;   arr[1]=false;

    for(int i=2; i*i<=n; i++) {                     // root (n)
        if(arr[i]) {
            for(int j=i*i; i<n; j+=i) {             // log (root(n))
                arr[j]=false;
            }
        }
    }
}

// root(n) log(root(n))

int main()
{
    int n;   cin>>n;
    vector<bool> arr(n+1, true);
    sieveAlgo(arr, n+1);
    printPrimes(arr);
}
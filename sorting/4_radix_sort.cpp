#include <bits/stdc++.h>
#define ll long long
using namespace std;

/*

*/

void outArray(vector<int> &arr) {
    for(int i=0; i<arr.size(); i++) cout<<arr[i]<<" ";
    cout<<"\n";
}

int digitCnt(int n) {
    int x = n;
    int cnt=0;
    while(x) {
        x/=10; cnt++;
    }

    return cnt;
}

void countSort(vector<int> &arr, int p) {
    int n=arr.size();
    vector<int> cnt(10, 0);
    p = (p==0) ? 1 : pow(10, p);
    cout<<p<<"\n";

    for(int i=0; i<10; i++) cnt[(arr[i]/p)%10]++;
    for(int i=1; i<10; i++) cnt[i]+=cnt[i-1];
    // outArray(cnt);

    vector<int> outArr(n);
    for(int i=n-1; i>=0; i--) {
        outArr[cnt[(arr[i]/p)%10]-1] = arr[i]; cnt[(arr[i]/p)%10]--;
    }
    outArray(outArr);

    for(int i=0; i<n; i++) arr[i]=outArr[i];
}

void radixSort(vector<int> &inArr) {
    int n = inArr.size(); 
    int maxx = *max_element(inArr.begin(), inArr.end());
    int digCnt = digitCnt(maxx);

    for(int i=0; i<digCnt; i++) {
        countSort(inArr, i);
    }

    outArray(inArr);
}

int main() {
    vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};
    radixSort(arr);
}
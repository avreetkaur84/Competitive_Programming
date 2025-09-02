#include <bits/stdc++.h>
#define ll long long
using namespace std;

/*
    ## Algorithm
    1. You have an input array. Find the max element from the input array and create a new array named cntArr of size max+1.
    2. In cntArr, fill the value of each index with the freq of idx element occurence in the input array
    3. Calculate the prefix sum of the array.
    4. Create a new outputArr with the size n, that is size of input array.
    5. Start traversing from the last index and tehn perfrom the operation outArr[cntArr[input[i]]-1]=inputArr[i]; 
    6. cnt[inputArr[i]]--;

    ## Points
    1. It is unstable sorting algorithm
    2. Only used when array size is smaller and range is also small
    4. Complexities: 
        1. TC : O(N+M)
            - N = size of input array
            - M = size of count array
        2. SC : O(N+M)
            - N = space for output array
            - M = space for count array
*/

void outArray(vector<int> &arr) {
    for(int i=0; i<arr.size(); i++) cout<<arr[i]<<" ";
    cout<<"\n";
}

void countSort(vector<int> &inArr) {
    int maxx = *max_element(inArr.begin(), inArr.end()), n=inArr.size();
    vector<int> cnt(maxx+1, 0);
    for(auto it : inArr) cnt[it]++;
    for(int i=1; i<cnt.size(); i++) cnt[i]+=cnt[i-1];
    vector<int> outArr(n);
    outArray(cnt);

    for(int i=n-1; i>=0; i--) {
        outArr[cnt[inArr[i]]-1] = inArr[i];
        cnt[inArr[i]]--;
    }

    outArray(outArr);
}

int main() {
    vector<int> arr = {5, 6, 7, 1, 2, 7, 3, 9, 2, 1, 1};
    countSort(arr); 
}


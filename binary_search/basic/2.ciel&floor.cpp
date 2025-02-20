// Question Link - https://www.geeksforgeeks.org/problems/ceil-the-floor2802/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=ceil-the-floor

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User code template

class Solution {
  public:
    vector<int> getFloorAndCeil(int x, vector<int> &arr) {
        // code here
        int low = 0;
        int high = arr.size()-1;
        int mid, floor_idx=-1, ceil_idx=-1;
        
        sort(arr.begin(), arr.end());
        
        // floor
        while(low<=high) {
            mid = (high+low)/2;
            
            if(arr[mid]<=x) {
                floor_idx = mid;
                low = mid+1;
            } else {
                high = mid-1;
            }
        }
        
        // cout<<"floor"<<floor_idx<<endl;
        
        // ceil
        low = 0;    high = arr.size()-1;
        
        while(low<=high) {
            mid = (low+high)/2;
            
            if(arr[mid]<x)  low = mid+1;
            else {
                ceil_idx = mid;
                high = mid-1;
            }
        }
        
        // cout<<"ciel"<<ceil_idx<<endl;
        
        vector<int> res = {arr[floor_idx], arr[ceil_idx]};
        
        if(arr[0]>x)    res[0] = -1;
        if(arr[arr.size()-1]<x)    res[1] = -1;
        
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline character after t
    while (t--) {
        vector<int> arr;
        int x;
        string input;
        cin >> x;
        cin.ignore();

        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        auto ans = ob.getFloorAndCeil(x, arr);
        cout << ans[0] << " " << ans[1] << "\n~\n";
    }
    return 0;
}
// } Driver Code Ends
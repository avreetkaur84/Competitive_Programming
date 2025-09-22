// Question Link - https://leetcode.com/problems/largest-rectangle-in-histogram/description/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Solution {
public:
    /*
        We have to find the max area of a rectangle in the histogram
        - Now, to find this, we have to check how far from left and right a particular bar can expand. Means, a bar can expand till the time its nor have the another bar that is smaller to it.
        - So, by finding the smallest index to the left and smallest idx to the right, we can find the range of the bar.
        - Lesson: Jab bhi range mein kujj find karna ho, like esse shotte ja barre jaisa kujj
    */

    using pi = pair<int, int>;

    void sel(vector<int>& heights, vector<int>& ps) {
        stack<pi> st;
        for(int i=0; i<heights.size(); i++) {
            while(!st.empty() && st.top().first>=heights[i]) st.pop();
            if(st.empty()) ps[i]=-1;
            else ps[i]=st.top().second;
            st.push({heights[i], i});
        }
    }

    void ser(vector<int>& heights, vector<int>& ps) {
        stack<pi> st; int n=heights.size();
        for(int i=n-1; i>=0; i--) {
            while(!st.empty() && st.top().first>=heights[i]) st.pop();
            if(st.empty()) ps[i]=n;
            else ps[i]=st.top().second;
            st.push({heights[i], i});
        }
    }

    void display(vector<int> arr) {
        for(int i=0; i<arr.size(); i++) cout<<arr[i]<<" ";
        cout<<"\n";
    }

    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> sl(n); sel(heights, sl);   // smallest ele to left
        vector<int> sr(n); ser(heights, sr);   // smallest ele to right
        // display(sl);  display(sr);
        
        // range find of bar: sr[i]-sl[i]-1
        int area=0;
        for(int i=0; i<n; i++) {
            int x = (sr[i]-sl[i]-1)*heights[i];
            area = max(area, x);
        }

        return area;
    }
};
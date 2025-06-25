// Question Link - 

#include <bits/stdc++.h>
#define ll long long
using namespace std;

class MedianFinder {
public:
    /*
        My intution - 
        1. We need to find median continously, means at every step automatically median should be ready. 
        2. For median to be ready, we need to have the total_elements/2 element but in sorted order.
        3. So, I will use vector array to store all the numbers and from this array I can keep the check on n- total element so far, but I can do this with the help of simple variable also, lets see how else I can use array.
        4. Then, as I don't need to sort all the elements but only the n/2 th element, so I can use heap of size n/2 for odd and (n/2)+1 for even, then I can have the max element at top. Which will be the median also.
        5. But the problem that I am facing is, how to delete the elements from heap, like If I take max heap of size n/2, then no doubt I will get median everytime at top, but it will remove the other greater elements from heap, which will be used later on as we can only add elements not remove, so everytime, median will be greater than last time. but if I use min heap, to remove the small elements, then I won't ge n/2 th element on top.
        6. Need to brainstrom here. So, I will use two heaps, one min heap, for eliminating the elements and one max heap for getting the median. No, this approach won't work as it will creaet lot of choas in removing and inserting elements. Then what??
        7. EDGE CASES PROBLEM!!!!!!
    */

    priority_queue<int> mx;
    priority_queue<int, vector<int>, greater<int>> mn;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(mn.empty() || num<mn.top()) mx.push(num);
        else mn.push(num);

        if(abs(int(mn.size()-mx.size()))>1) {
            if(mn.size()>mx.size()) {
                mx.push(mn.top()); mn.pop();
            } else {
                mn.push(mx.top()); mx.pop();
            }
        }
    }
    
    double findMedian() {
        if(mn.empty() && mx.empty()) return NULL;

        if(mn.size()==mx.size()) {
            return (double(mn.top())+mx.top())/2;
        } else {
            if(mn.size()>mx.size()) return mn.top();
            else return mx.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
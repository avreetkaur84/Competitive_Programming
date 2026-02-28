#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
private:
    int seg[10500] = {0};
    vector<int> arr;

public:
    SegmentTree(vector<int> &a) {
        arr = a;
    }

    int buildTree(int idx, int left, int right) {
        if(left==right) {
            seg[idx]=arr[left]; 
            return seg[idx];
        }

        int mid = (left+right)/2;
        int interval_1 = buildTree(2*idx+1, left, mid);
        int interval_2 = buildTree(2*idx+2, mid+1, right);
        return seg[idx] = interval_1+interval_2;
    }   
    
    int calculate(int idx, int QL, int QR, int left, int right) {
        if(QL>right || QR<left) return 0;
        else if(QL<=left && QR>=right) return seg[idx];
        else {
            int mid = (left+right)/2;
            int range_1 = calculate(2*idx+1, QL, QR, left, mid);
            int range_2 = calculate(2*idx+2, QL, QR, mid+1, right);
            return range_1+range_2;
        }
    }

    void display() {
        cout<<"Segment Tree: ";
        for(int i=0; i<4*arr.size(); i++) cout<<seg[i]<<" ";
        cout<<"\n";
    }
};

int main() {
    vector<int> arr = {5,2,4,8,3,6,5,4};
    SegmentTree s(arr);
    s.buildTree(0, 0, arr.size()-1);
    s.display();
    int x = s.calculate(0, 2, 5, 0, arr.size()-1);
    cout<<"Query Result: "<<x<<"\n";
}
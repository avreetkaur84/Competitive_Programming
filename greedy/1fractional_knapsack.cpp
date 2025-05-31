// Question Link - https://www.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1

#include <bits/stdc++.h>
#define ll long long
using namespace std;

    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n=val.size(); vector<vector<double>> op; 
        double maxx=0;
        for(int i=0; i<n; i++) {
            double o=(double)val[i]/wt[i];
            op.push_back({o, (double)val[i], (double)wt[i]});
        }
        
        sort(op.begin(), op.end(), [](const vector<double>& a, const vector<double>& b) {
            return a[0] > b[0]; 
        });
        
        int g;
        
        for(g=0; g<n; g++) {
            if(capacity-op[g][2]>=0) {
                maxx+=op[g][1];
                capacity-=op[g][2];
            } else break;
            // cout<<"maxx: "<<maxx<<" capacity: "<<capacity<<endl;
        }
        
        if(capacity>0 && g<n) {
            maxx+=((double)capacity/op[g][2])*op[g][1];
        }
        
        return round(maxx * 1e6) / 1e6;
        
    }
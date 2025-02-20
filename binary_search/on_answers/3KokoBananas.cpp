#include <bits/stdc++.h>
using namespace std;

// MOST OPTIMAL SOLUTION
class Solution {
    public:
        bool canFinish(vector<int>& piles, int k, int h) {
            int hours = 0;
            for (int pile : piles) {
                hours += (pile + k - 1) / k;  
            }
            return hours <= h;
        }
    
        int minEatingSpeed(vector<int>& piles, int h) {
            int left = 1;
    
            int right = piles[0]; 

            // found max
            for (int pile : piles) {
                if (pile > right) {
                    right = pile;
                }
            }
    
            while (left < right) {
                int mid = left + (right - left) / 2;
                
                if (canFinish(piles, mid, h)) {
                    right = mid;  
                } else {
                    left = mid + 1;
                }
            }
            return left;  
        }
    };



// my solution
class Solution {
public:
    long totalHoursCal(vector<int> &piles, int x) {
        long totalHours = 0;
        // cout<<"Total Hours for "<<x<<" : ";
        for(int i=0; i<piles.size(); i++) {
            int ceilHour = ceil((double)piles[i]/(double)x);
            totalHours = totalHours + ceilHour;
            // cout<<ceilHour<<" ";
        }
        // cout<<endl;
        cout<<"Total Hours for mid : "<<x<<" = "<<totalHours<<endl;
        // if(totalHours<0)    return -1;
        return totalHours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        // we have given total hours, and piles of bananas,
        // Koko has to finish one pile before moving to next
        // we have to calculate minimum bananas she needs to eat in an hour, to finish all bananas in given hours.

        // we have to find the range of bananas she can eat in an hour, so condition is she can't move to next pile, before finishing one, so maximum bananas she can eat will be maximum bananas in pile aaray. range = 1 to max(pile)
        int high = *max_element(piles.begin(), piles.end());
        int low = 1, mid;
        // cout<<high<<endl;

        // now, we need to calculate total hours a koko will take to eat all bananas if she is eating mid bananas at once. Need to create function

        // edge case-totalHours can't be negative
        while(low<=high) {
            mid = low+(high-low)/2;

            long totalHours = totalHoursCal(piles, mid);

            // if(totalHours==-1) {
            //      cout<<"Executed"<<endl;
            //      return prevLow;
            // }
            // cout<<"Total Hours for mid : "<<mid<<" = "<<totalHours<<endl;
            // if(totalHours==h)   return mid;
            if(totalHours<=h)   high=mid-1;
            else {
                // prevLow = low;
                low=mid+1;
            }
        }

        return low;
    }

};

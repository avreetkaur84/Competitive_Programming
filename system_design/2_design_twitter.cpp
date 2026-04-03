// Question Link - https://leetcode.com/problems/design-twitter/description/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Twitter {
private: 
    int count;
    unordered_map<int, set<int>> user_foll;
    unordered_map<int, vector<pair<int, int>>> tweet;


public:
    Twitter() {
        count=0;
    }
    
    void postTweet(int userId, int tweetId) {
        count++;
        tweet[userId].push_back({count, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        user_foll[userId].insert(userId);
        if(user_foll.find(userId)!=user_foll.end()) {
            for(const auto &i: user_foll[userId]) {
                if(tweet.find(i)!=tweet.end()) {
                    for(const auto& j: tweet[i]) {
                        pq.push(j);
                        if(pq.size()>10) {
                            pq.pop();
                        }
                    }
                }
            }
        }

        vector<int> arr;
        while(!pq.empty()) {
            arr.push_back(pq.top().second);
            pq.pop();
        }

        reverse(arr.begin(), arr.end());

        return arr;
    }
    
    void follow(int followerId, int followeeId) {
        user_foll[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if (user_foll.count(followerId) && user_foll[followerId].count(followeeId)) {
            user_foll[followerId].erase(followeeId);
        }
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */


// Use .count() when: You just need to check existence.
// Use .find() when: You need the iterator (e.g., to erase by iterator or access the value).
// if(mp.find(followerId)!=mp.end()) {
        //     if(mp[followerId].find(followeeId)!=mp[followerId].end()) {
        //         mp[followerId].erase(followeeId);
        //     }
        // }

// Question Link - https://leetcode.com/problems/design-a-food-rating-system/description/?envType=daily-question&envId=2025-09-19

#include <bits/stdc++.h>
#define ll long long
using namespace std;

class FoodRatings {
public:
    using item = pair<int, string>;

    struct comp {
        bool operator()(const item &a, const item &b) const {
            if(a.first==b.first) return a.second<b.second;  
            return a.first>b.first;   
        }
    };
    
    unordered_map<string, set<item, comp>> cuisine_mp;
    unordered_map<string, item> food_mp;

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i=0; i<cuisines.size(); i++) {
            cuisine_mp[cuisines[i]].insert({ratings[i], foods[i]});
        }

        for(int i=0; i<foods.size(); i++) {
            food_mp[foods[i]] = {ratings[i], cuisines[i]};
        }
    }
    
    void changeRating(string food, int newRating) {
        // modify food item rating
        string c_name = food_mp[food].second;
        int old_rating = food_mp[food].first;
        food_mp[food].first = newRating;

        cuisine_mp[c_name].erase({old_rating, food});
        cuisine_mp[c_name].insert({newRating, food});
    }
    
    string highestRated(string cuisine) {
        for(auto it : cuisine_mp[cuisine]) return it.second;
        return "";
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
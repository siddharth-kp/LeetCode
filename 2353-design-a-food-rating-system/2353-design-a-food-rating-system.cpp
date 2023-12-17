class FoodRatings {
public:
    unordered_map<string, pair<int, string>> foodCuisineMap;
    map<string, map<int, set<string>>> cuisineRatingMap;
    
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings)
    {
        int n = foods.size();
        for (int i = 0; i < n; ++i)
        {
            foodCuisineMap[foods[i]] = {ratings[i], cuisines[i]};
            cuisineRatingMap[cuisines[i]][ratings[i]].insert(foods[i]);
        }
    }
    
    void changeRating(string food, int newRating)
    {
        auto& [oldRating, cuisine] = foodCuisineMap[food];
        auto& cuisineData = cuisineRatingMap[cuisine];
        cuisineData[oldRating].erase(food);
        if (cuisineData[oldRating].size() == 0)
            cuisineData.erase(oldRating);
        cuisineRatingMap[cuisine][newRating].insert(food);
        foodCuisineMap[food].first = newRating;
    }
    
    string highestRated(string cuisine)
    {
        auto& foodsWithHighestRating = cuisineRatingMap[cuisine].rbegin()->second;
        return *(foodsWithHighestRating.begin());
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
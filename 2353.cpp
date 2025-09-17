class FoodRatings {
public:
    unordered_map<string,set<pair<int,string>>> cousin_rating_food;
    unordered_map<string,string> food_cousin;
    unordered_map<string,int> food_rating;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();

        for(int i = 0;i<n;i++){
            string food = foods[i];
            string cousin = cuisines[i];
            int rating = ratings[i];

            cousin_rating_food[cousin].insert({-rating,food});
            food_cousin[food] = cousin;
            food_rating[food] = rating;
        }
    }
    
    void changeRating(string food, int newRating) {
        int old_rating = food_rating[food];
        string cousin = food_cousin[food];

        food_rating[food] = newRating;

        cousin_rating_food[cousin].erase({-old_rating,food});
        cousin_rating_food[cousin].insert({-newRating,food});
    }
    
    string highestRated(string cuisine) {
        return begin(cousin_rating_food[cuisine])->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */

class MovieRentingSystem {
public:
    unordered_map<int,set<pair<int,int>>> available;
    unordered_map<int,set<pair<int,int>>> movieToshop;
    set<tuple<int,int,int>> rented;
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for(auto& vec: entries){
            int shop = vec[0];
            int movie = vec[1];
            int price = vec[2];

            available[movie].insert({price,shop});
            movieToshop[movie].insert({shop,price});
        }
    }
    
    vector<int> search(int movie) {
        int count = 0;
        vector<int> result;
        if(available.count(movie)){
            for(auto& [price,shop]: available[movie]){
                result.push_back(shop);
                count++;
                if(count >= 5)break;
            }
        }

        return result;
    }
    
    void rent(int shop, int movie) {
        auto it = movieToshop[movie].lower_bound({shop,INT_MIN});
        int price = it->second;

        available[movie].erase({price,shop});
        rented.insert({price,shop,movie});
    }
    
    void drop(int shop, int movie) {
        auto it = movieToshop[movie].lower_bound({shop,INT_MIN});
        int price = it->second;

        available[movie].insert({price,shop});
        rented.erase({price,shop,movie});
    }
    
    vector<vector<int>> report() {
        vector<vector<int>> result;
        int count = 0;
        for(auto &[prices,shop,movie]: rented){
            result.push_back({shop,movie});
            count++;
            if(count >= 5) break;
        }

        return result;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */

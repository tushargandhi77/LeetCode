class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string,int> mp;

        for(auto& path: paths){
            mp[path[0]]++;
        }


        for(auto& path: paths){
            if(!mp.count(path[1])){
                return path[1];
            }
        }

        return "";
    }
};

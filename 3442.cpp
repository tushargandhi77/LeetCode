class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char,int> mp;

        for(char c: s){
            mp[c]++;
        }

        int maxodd = 0;
        int mineven = INT_MAX;

        for(auto it: mp){
            if(it.second % 2 == 0){
                mineven = min(mineven,it.second);
                
            }
            else{
                maxodd = max(maxodd,it.second);
            }
        }

        return maxodd - mineven;
    }
};

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        unordered_map<int,int> mp;

        int i = 0;
        int j = 0;


        int result = 0;
        while(j < n){
            mp[fruits[j]]++;

            while(mp.size() > 2){
                int val = fruits[i];
                mp[val]--;
                if(mp[val] == 0) mp.erase(val);
                i++;
            }

            result = max(result,j-i+1);
            j++;
        }

        return result;
    }
};

class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        unordered_map<int,int> mp;

        for(int& num: nums){
            mp[num]++;
        }

        vector<int> t;

        for(auto it : mp){
            if(it.second == 2){
                t.push_back(it.first);
            }
        }

        return t;
    }
};

class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int XOR = 0;
        int n = nums.size()-2;

        for(int& num: nums){
            XOR ^= num;
        }

        for(int i = 0;i<n;i++){
            XOR ^= i;
        }

        int trailingzero = __builtin_ctz(XOR);
        int mask = 1 << trailingzero;

        int G1 = 0;
        int G2 = 0;

        for(int& num: nums){
            if(mask & num){
                G1 ^= num;
            }
            else{
                G2 ^= num;
            }
        }

        for(int i = 0;i<n;i++){
            if(mask & i){
                G1 ^= i;
            }
            else{
                G2 ^= i;
            }
        }

        return {G1,G2};
    }

};

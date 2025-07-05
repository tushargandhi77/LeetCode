class Solution {
public:
    int findLucky(vector<int>& arr) {
        map<int,int> mp; // make in osorted order

        for(int& num: arr){
            mp[num]++;
        }

        int largest = -1;
        for(auto [val,freq] : mp){
            if(val == freq){
                largest = val;
            }
        }

        return largest;

    }
};

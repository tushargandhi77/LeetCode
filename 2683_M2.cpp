class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int result = 0;

        for(auto& dev : derived){
            result ^= dev;
        }

        return result == 0 ? true : false;
    }
};

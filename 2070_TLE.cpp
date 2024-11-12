class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        vector<int> result;

        for(auto &que:queries){
            int max_beauty = INT_MIN;
            for(auto& vec:items){
                if(que >= vec[0]){
                    max_beauty = max(max_beauty,vec[1]);
                }
            }
            if(max_beauty==INT_MIN){
                result.push_back(0);
                continue;
            }
            result.push_back(max_beauty);
        }
        return result;
    }
};

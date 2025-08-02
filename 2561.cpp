class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int,int> mp;
        int minElement = INT_MAX;

        for(int& num: basket1){
            mp[num]++;
            minElement = min(minElement,num);
        }

        for(int& num: basket2){
            mp[num]--;
            minElement = min(minElement,num);
        }

        vector<int> finalList;

        for(auto it: mp){
            int val = it.first;
            int count = it.second;

            if(count == 0) continue;

            if(count % 2 != 0){
                return -1;
            }

            for(int c = 1;c<=abs(count)/2;c++){
                finalList.push_back(val);
            }

        }

        sort(begin(finalList),end(finalList));

        long long result = 0;
        for(int i = 0;i<finalList.size()/2;i++){
            result += min(finalList[i],2 * minElement);
        }

        return result;
    }
};

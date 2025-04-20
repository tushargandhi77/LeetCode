class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int> mp;

        for(auto& num: answers){
            mp[num]++;
        }

        int answer = 0;

        for(auto [x, count] : mp){
            int groups = ceil((double)count/(x+1));
            answer += groups*(x+1);
        }

        return answer;
    }
};

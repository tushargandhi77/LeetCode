class Solution {
public:
    int solve(unordered_map<int,int>& mp,int x){
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

        for(auto [key,val]: mp){
            pq.push({val,key});

            if(pq.size() > x){
                pq.pop();
            }
        }

        int result = 0;

        while(!pq.empty()){
            auto [val,key] = pq.top();
            pq.pop();

            result += val*key;
        }

        return result;
    }
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        unordered_map<int,int> freq;

        int n = nums.size();
        vector<int> result;

        int i = 0;
        int j = 0;

        while(j < n){
            freq[nums[j]]++;

            if(j - i + 1 == k){
                result.push_back(solve(freq,x));

                freq[nums[i]]--;
                if(freq[nums[i]] == 0){
                    freq.erase(nums[i]);
                }
                i++;
            }
            j++;
        }

        return result;
    }
};

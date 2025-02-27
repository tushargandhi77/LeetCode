class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> t(n,vector<int>(n,2));

        unordered_map<int,int> mp;

        for(int i = 0;i<n;i++){
            mp[arr[i]] = i;
        }

        int maxLength = 0;

        for(int j = 1;j<n;j++){
            for(int k = j+1;k<n;k++){
                int target = arr[k] - arr[j];

                if(mp.count(target) && mp[target] < j){
                    int i = mp[target];
                    t[j][k] = t[i][j] + 1;
                }
                maxLength = max(maxLength,t[j][k]);
            }

        }

        return maxLength >= 3 ? maxLength : 0;
    }
};

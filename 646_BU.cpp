class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();

        sort(pairs.begin(),pairs.end());

        vector<int> t(n,1);

        for(int i = 0;i<n;i++){
            int val = t[i];

            for(int j = 0;j<i;j++){
                if(pairs[i][0] > pairs[j][1]){
                    t[i] = max(t[i],t[j]+val);
                }
            }
        }

        return *max_element(begin(t),end(t));
    }
};

class Solution {
public:
    int t[1001][1001];
    int solve(int j,int k,vector<int>& arr,unordered_map<int,int>& mp){
        int target = arr[k] - arr[j];

        if(t[j][k] != -1) return t[j][k];

        if(mp.count(target) && mp[target] < j){
            int i = mp[target];
            return t[j][k] = solve(i,j,arr,mp) + 1;
        }
        return t[j][k] = 2;
    }
    int lenLongestFibSubseq(vector<int>& arr) {

        memset(t,-1,sizeof(t));
        int n = arr.size();

        unordered_map<int,int> mp;

        for(int i = 0;i<n;i++){
            mp[arr[i]] = i;
        }

        int maxLength = 0;

        for(int j = 1;j<n;j++){
            for(int k = j+1;k<n;k++){
                int length = solve(j,k,arr,mp);
                if(length >= 3){
                    maxLength = max(length,maxLength);
                }
            }
        }
        return maxLength;

    }
};

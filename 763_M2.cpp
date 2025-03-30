class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.length();

        vector<int> mp(26,0);

        for(int i = 0;i<n;i++){
            int idx = s[i] - 'a';
            mp[idx] = i;
        }
        vector<int> result;
        int i = 0;
        int start = 0;
        int end = 0;
        while(i < n){
            end = max(mp[s[i]-'a'],end);

            if(i == end){
                result.push_back({i-start+1});
                start = end + 1;
            }
            i++;
        }
        return result;
    }
};

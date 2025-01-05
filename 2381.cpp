class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.length();
        vector<int> nums(n,0);

        for(auto& vec: shifts){
            int start = vec[0];
            int end = vec[1];
            int dir = vec[2] == 1 ? 1 : -1;

            nums[start] = nums[start] + dir;

            if(end+1 < n){
                nums[end+1] = nums[end+1] - dir;
            }
        }

        for(int i = 1;i<n;i++){
            nums[i] = nums[i-1] + nums[i];
        }

        for(int i = 0;i<n;i++){
            int sh = nums[i] % 26;

            if(sh < 0){
                sh += 26;
            }

            s[i] = ((s[i] - 'a' + sh) % 26) + 'a';
        }

        return s;
    }
};

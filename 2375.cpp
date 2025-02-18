class Solution {
public:
    bool matchpattern(string& nums,string& pattern,int n){
        for(int i = 0;i<pattern.length();i++){
            if(pattern[i]=='I' && nums[i] > nums[i+1]) return false;
            if(pattern[i] == 'D' && nums[i] < nums[i+1]) return false;
        }
        return true;
    }
    string smallestNumber(string pattern) {
        int n = pattern.size();
        string nums = "";
        for(int i = 1;i<=n+1;i++){
            nums.push_back(i + '0');
        }
        while(!matchpattern(nums,pattern,n)){
            next_permutation(begin(nums),end(nums));
        }
        return nums;
    }
};

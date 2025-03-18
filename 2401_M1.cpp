class Solution {
public:
    bool isNice(vector<int>& nums,int l,int r){
        int mask = 0;

        for(int i = l;i<=r;i++){
            if((mask & nums[i]) != 0) return false;
            mask |= nums[i];
        }

        return true;
    }
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        int result = INT_MIN;
        for(int i = 0;i<n;i++){
            for(int j = i;j<n;j++){
                if(isNice(nums,i,j)){
                    result = max(result,j-i+1);
                }
                else{
                    break;
                }
            }
        }

        return result;
    }
};

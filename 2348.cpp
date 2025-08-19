class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long result = 0;
        int n = nums.size();
        
        int count = 0;
        for(int i = 0;i<n;i++){
            if(nums[i] == 0){
                count++;
            }
            else{
                result += ((long long)count*(count+1))/2;
                count = 0;
            }
        }

        if(count > 0){
            result += ((long long)count*(count+1))/2;
        }

        return result;
    }
};


class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long result = 0;
        int n = nums.size();
        
        long long count  = 0;
        for(int i = 0;i<n;i++){
            if(nums[i] == 0){
                count++;
            }
            else{
                count = 0;
            }

            result += count;
        }

        return result;
    }
};

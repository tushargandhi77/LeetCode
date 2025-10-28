class Solution {
public:
    bool check(vector<int>& nums,int i,int count,int dir){
        auto temp = nums;
        int idx = i;
        
        while(idx >= 0 &&  idx < nums.size() && count > 0){
            if(temp[idx] > 0){
                temp[idx]--;
                dir *= -1;

                if(temp[idx] == 0){
                    count--;
                }
            }
            idx += dir;
        }

        return count  == 0;
    }
    int countValidSelections(vector<int>& nums) {
        int result = 0;
        int count = 0;

        for(int i = 0;i<nums.size();i++){
            if(nums[i] != 0) count++;
        }

        for(int i = 0;i<nums.size();i++){
            if(nums[i] == 0){
                if(check(nums,i,count,1)){
                    result++;
                }
                if(check(nums,i,count,-1)){
                    result++;
                }
            }
        }

        return result;
    }
};


class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int total = accumulate(begin(nums),end(nums),0);

        int currsum = 0;

        int result = 0;

        for(int& num: nums){
            currsum += num;

            if(num == 0){
                int sum2 = total - currsum;

                if(sum2 == currsum) result += 2;
                else if(abs(sum2 - currsum) == 1) result++;
            }
        }

        return result;
    }
};

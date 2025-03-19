class Solution {
public:
    
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        int flips = 0;

        int flipCountFromPasti = 0;

        vector<bool> isFlipped(n,false);

        for(int i = 0;i<n;i++){
            if(i >= 3 && isFlipped[i-3] == true){
                flipCountFromPasti--;
            }

            if(flipCountFromPasti % 2  == nums[i]){
                if(i+3 > n){
                    return -1;
                }

                flipCountFromPasti++;
                flips++;
                isFlipped[i] = true;
            }
        }

        return flips;
        
    }
};

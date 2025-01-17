class Solution {
public:
    void addinwindow(int number,vector<int>& vec){
        for(int i = 0;i<32;i++){
            if((number >> i) & 1){
                vec[i]++;
            }
        }
    }
    void removeFromwindow(int number,vector<int>& vec){
        for(int i = 0;i<32;i++){
            if((number>>i) & 1){
                vec[i]--;
            }
        }
    }
    int getDecimalNumber(vector<int>& vec){
        int num = 0;
        for(int i = 0;i<32;i++){
            if(vec[i] > 0){
                num |= (1 << i);
            }
        }
        return num;
    }
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();

        int result = INT_MAX;

        int i = 0;
        int j = 0;

        vector<int> vec(32,0);

        while(j < n){
            addinwindow(nums[j],vec);

            while(i<=j && getDecimalNumber(vec) >= k){
                result = min(result,j-i+1);
                removeFromwindow(nums[i],vec);
                i++;
            }

            j++;
        }
        return result == INT_MAX ? -1 : result;
    }
};

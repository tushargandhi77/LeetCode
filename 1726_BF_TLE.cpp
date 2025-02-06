class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int result = 0;
        int n = nums.size();

        for(int i = 0;i<n;i++){
            for(int j = i+1;j<n;j++){
                for(int k = 0;k<n;k++){
                    for(int l = k+1;l<n;l++){
                        if(i != k && i != l && j != k && j != l){
                            int p1 = nums[i] * nums[j];
                            int p2 = nums[k] * nums[l];

                            if(p1 == p2) result ++;
                        }
                    }
                }
            }
        }
        return (result*8)/2;
    }
};

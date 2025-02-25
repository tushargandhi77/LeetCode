class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int count = 0;
        int n = arr.size();
        for(int i = 0;i<n;i++){
            for(int j = i;j<n;j++){
                int sum = 0;
                for(int k = i;k<=j;k++){
                    sum += arr[k];
                }
                if(sum % 2 != 0) count++;
            }
        }
        return count;
    }
};

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();

        vector<int> prefixMax(n);
        vector<int> suffixMin(n);
        int max = INT_MIN;
        int min = INT_MAX;
        for(int i = 0;i<n;i++){
            if(max < arr[i]){
                max = arr[i];
                prefixMax[i] = max;
            }
            else{
                prefixMax[i] = max;
            }
        }
        for(int i = n-1;i>=0;i--){
            if(min > arr[i]){
                min = arr[i];
                suffixMin[i] = min;
            }
            else{
                suffixMin[i] = min;
            }
        }
        int result = 0;
        for(int i = 0;i<n;i++){
            int premax = i > 0 ? prefixMax[i-1] : -1;
            int premin  = suffixMin[i];

            if(premax<premin){
                result++;
            }
        }

        return result;
    }
};

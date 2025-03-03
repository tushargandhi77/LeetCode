class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();

        int countless = 0;
        int countequal = 0;

        for(int& num: nums){
            if(num < pivot) countless++;
            if(num == pivot) countequal++;
        }

        int i = 0;
        int j = countless;
        int k = countless+countequal;

        vector<int> result(n);

        for(int& num: nums){
            if(num < pivot){
                result[i] = num;
                i++;
            }
            else if(num == pivot){
                result[j] = num;
                j++;
            }
            else{
                result[k] = num;
                k++;
            }
        }
        return result;
    }
};

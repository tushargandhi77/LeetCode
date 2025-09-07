class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> arr(n,0);

        for(int i = 1;i<n;i++){
            arr[i] = i;
        }

        int sum = accumulate(begin(arr),end(arr),0);

        arr[0] = -sum;

        return arr;
    }
};

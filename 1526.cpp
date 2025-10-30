class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int result = 0;
        int prev = 0;
        int n = target.size();

        for(int i = 0;i<n;i++){
            int curr = target[i];

            if(curr > prev){
                result += (curr - prev);
            }

            prev = curr;
        }

        return result;
    }
};

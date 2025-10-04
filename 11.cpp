class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();

        int l = 0;
        int r = n-1;
        int result = INT_MIN;
        while(l < r){
            int ans = min(height[l],height[r]) * (r-l);
            result = max(ans,result);

            if(height[l] < height[r]){
                l++;
            }
            else if(height[l] > height[r]){
                r--;
            }
            else{
                l++;
                r--;
            }
        }

        return result;
    }
};

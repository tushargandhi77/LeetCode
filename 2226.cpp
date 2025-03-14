class Solution {
public:
    bool check(vector<int>& candies, int val,long long k){

        for(int i = 0;i<candies.size();i++){
            k -= candies[i]/(long long)val;
            if(k <= 0) return true;
        }

        return k <= 0;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int maxC = *max_element(begin(candies),end(candies));
        long long totalCandy = accumulate(begin(candies),end(candies),(long long) 0);

        if(totalCandy < k) return 0;

        int l = 1;
        int r = maxC;

        int result = 0;
        while(l <= r){
            int mid = l + (r-l)/2;

            if(check(candies,mid,k) == true){
                result = mid;
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }
        return result;
    }
};

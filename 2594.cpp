class Solution {
public:
    bool ispossile(vector<int>& ranks,long long mid,int cars){
        long long totalcar = 0;

        for(int i = 0;i<ranks.size();i++){
            totalcar += sqrt(mid/ranks[i]);
        }

        return totalcar >= cars;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        int maxR = *max_element(begin(ranks),end(ranks));
        long long l = 1;
        long long r = (long long)maxR * cars * cars;
        long long result = -1;
        while(l <= r){
            long long mid = l + (r - l)/2;

            if(ispossile(ranks,mid,cars)){
                result = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return result;
    }
};

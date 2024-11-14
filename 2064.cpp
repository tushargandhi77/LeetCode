class Solution {
public:
    bool possibletodistribute(int x,vector<int>& quantities,int n){
        int count = 0;

        for(int& val:quantities){
            count += (val + x -1)/x;
        }

        if(count > n) return false;

        return true;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int l = 1;
        int r = *max_element(begin(quantities),end(quantities));

        int result = 0;
        while(l<=r){
            int mid = l + (r-l)/2;

            if(possibletodistribute(mid,quantities,n)){
                r = mid-1;
                result = mid;
            }
            else{
                l = mid+1;
            }
        }
        return result;
    }
};

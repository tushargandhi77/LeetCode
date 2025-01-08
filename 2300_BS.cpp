class Solution {
public:
    int binarysearch(int l,int r,int minVal,vector<int>& potions){

        int ans = -1;

        while(l<=r){
            int mid = l + (r-l)/2;

            if(potions[mid] >= minVal){
                ans = mid;
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return ans;
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        int m = potions.size();

        sort(potions.begin(),potions.end());
        int maxVal = potions[m-1];
        vector<int> result(n);
        for(int i = 0;i<n;i++){
            long long val = ceil((1.0* success)/spells[i]);

            if(val > maxVal){
                result[i] = 0;
                continue;
            }

            int idx = binarysearch(0,m-1,val,potions);

            result[i] = (m-idx);
        }
        return result;
    }
};

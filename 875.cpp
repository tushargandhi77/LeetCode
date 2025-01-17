class Solution {
public:
    bool caneatbanans(vector<int>& piles,int mid, int h){
        int actualhour = 0;

        for(int& x: piles){
            actualhour += x/mid;
            if(x % mid != 0){
                actualhour += 1;
            }
        }

        return actualhour <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int l = 1;
        int r = *max_element(begin(piles),end(piles));

        while(l < r){
            int mid = l + (r-l) / 2;

            if(caneatbanans(piles,mid,h)){
                r = mid; // trim
            }
            else{
                l = mid + 1;
            }
        }
        return l;
    }
};

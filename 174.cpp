// Method 1 : Brute Force BS

class Solution {
public:
    int m,n;

    bool cansurvive(int i,int j,int mid,vector<vector<int>>& dungeon){
        if(i >= m || j >= n) return false;

        mid += dungeon[i][j];

        if(mid <= 0) return false;

        if(i == m-1 && j == n-1) return true;

        return cansurvive(i+1,j,mid,dungeon) | cansurvive(i,j+1,mid,dungeon);
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        m = dungeon.size();
        n = dungeon[0].size();


        int left = 1;
        int right = 4 * 1e7;

        int result = INT_MAX;

        while(left<=right){
            int mid = left + (right-left)/2;

            if(cansurvive(0,0,mid,dungeon)){
                result = min(result,mid);
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }

        return result;
    }
};

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

// Method 2 : Brute force Memo

class Solution {
public:
    int m,n;

    unordered_map<string,bool> mp;
    bool cansurvive(int i,int j,int mid,vector<vector<int>>& dungeon){
        if(i >= m || j >= n) return false;

        mid += dungeon[i][j];

        if(mid <= 0) return false;

        if(i == m-1 && j == n-1) return true;

        string key = to_string(i) + "_" + to_string(j) + "_" + to_string(mid);

        if(mp.count(key)) return mp[key];

        return mp[key] = cansurvive(i+1,j,mid,dungeon) | cansurvive(i,j+1,mid,dungeon);
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        m = dungeon.size();
        n = dungeon[0].size();


        int left = 1;
        int right = 4 * 1e7;

        int result = 4 * 1e7;

        while(left<=right){
            int mid = left + (right-left)/2;
            mp.clear();
            if(cansurvive(0,0,mid,dungeon)){
                result = mid;
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }

        return result;
    }
};

// Method 3 :-> Recusion 

class Solution {
public:
    int m,n;

    int solve(int i,int j,vector<vector<int>>& dungeon){
        if(i < 0 || i >= m || j < 0 || j >= n){
            return INT_MAX;
        }

        if(i == m-1 && j == n-1){
            if(dungeon[i][j] <= 0){
                return abs(dungeon[i][j]) + 1;
            }
            else{
                return 1;
            }
        }


        int right = solve(i,j+1,dungeon);
        int bottom  = solve(i+1,j,dungeon);

        int result = min(right,bottom) - dungeon[i][j];

        return result <= 0 ? 1 : result;
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        m = dungeon.size();
        n = dungeon[0].size();

        return solve(0,0,dungeon);
    }
};


// Method 4 :-> Recusion + MEMO

class Solution {
public:
    int m,n;
    int t[201][201];
    int solve(int i,int j,vector<vector<int>>& dungeon){
        if(i < 0 || i >= m || j < 0 || j >= n){
            return INT_MAX;
        }

        if(i == m-1 && j == n-1){
            if(dungeon[i][j] <= 0){
                return abs(dungeon[i][j]) + 1;
            }
            else{
                return 1;
            }
        }

        if(t[i][j] != -1) return t[i][j];

        int right = solve(i,j+1,dungeon);
        int bottom  = solve(i+1,j,dungeon);

        int result = min(right,bottom) - dungeon[i][j];

        return t[i][j] = result <= 0 ? 1 : result;
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        m = dungeon.size();
        n = dungeon[0].size();
        memset(t,-1,sizeof(t));
        return solve(0,0,dungeon);
    }
};

// Method 5: -  Bottom Up

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();

        vector<vector<int>> t(m,vector<int>(n,0));

        for(int i = m-1;i>=0;i--){
            for(int j = n-1;j>=0;j--){
                if(i == m-1 && j == n-1){
                    if(dungeon[i][j] > 0){
                        t[i][j] =  1;
                    }
                    else{
                        t[i][j] = abs(dungeon[i][j]) + 1; 
                    }
                }

                else{
                    int right = j + 1 >= n ? 1e9 : t[i][j+1];
                    int down = i + 1 >= m ? 1e9 : t[i+1][j];

                    int result = min(right,down) - dungeon[i][j];

                    t[i][j] = result <= 0 ? 1 : result;
                }
            }
        }

        return t[0][0];
    }
};

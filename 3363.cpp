class Solution {
public:
    int n;
    vector<vector<int>> t;
    int fruitchild1(vector<vector<int>>& fruits){
        int fruit = 0;

        for(int i = 0;i<n;i++){
            fruit += fruits[i][i];
        }

        return fruit;
    }

    int fruitchild2(int i,int j,vector<vector<int>>& fruits){
        if(i >= n || j < 0 || j >= n) return 0;

        if(i == n-1 && j == n-1) return 0; // already taken by child1;

        if(i==j || i > j) return 0;

        if(t[i][j] != -1) return t[i][j];

        int bottomleft = fruits[i][j] + fruitchild2(i+1,j-1,fruits);
        int bottom = fruits[i][j] + fruitchild2(i+1,j,fruits);
        int bottomright = fruits[i][j] + fruitchild2(i+1,j+1,fruits);

        return t[i][j] = max({bottomright,bottom,bottomleft});
    }

    int fruitchild3(int i,int j,vector<vector<int>>& fruits){
        if(i < 0 || i >= n || j >= n) return 0;

        if(i == n-1 && j == n-1) return 0;

        if(i == j || i < j) return 0;

        if(t[i][j] != -1) return t[i][j];

        int righttop = fruits[i][j] + fruitchild3(i-1,j+1,fruits);
        int right = fruits[i][j] + fruitchild3(i,j+1,fruits);
        int rightbottom = fruits[i][j] + fruitchild3(i+1,j+1,fruits);
        

        return t[i][j] = max({righttop,right,rightbottom});
    }
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        n = fruits.size();

        t.resize(n,vector<int>(n,-1));

        int c1 = fruitchild1(fruits);

        int c2 = fruitchild2(0,n-1,fruits);

        int c3 = fruitchild3(n-1,0,fruits);

        return c1+c2+c3;
    }
};

// bottom up

class Solution {
public:
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int n = fruits.size();
        vector<vector<int>> t(n,vector<int>(n,0));

        int result = 0;
        for(int i = 0;i<n;i++){
            result += fruits[i][i];
        }

        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(i < j && i + j < n-1){
                    t[i][j] = 0;
                }
                else if(i > j && i + j < n-1){
                    t[i][j] = 0;
                }
                else{
                    t[i][j] = fruits[i][j];
                }
            }
        }

        // child 2

        for(int i = 1;i<n;i++){
            for(int j = i+1;j<n;j++){
                t[i][j] += max({t[i-1][j-1],t[i-1][j],j+1 < n ?  t[i-1][j+1] : 0});
            }
        }

        for(int j = 1;j<n;j++){
            for(int i = j+1;i<n;i++){
                t[i][j] += max({t[i-1][j-1],t[i][j-1],i+1 < n ? t[i+1][j-1] : 0});
            }
        }


        result += (t[n-1][n-2] + t[n-2][n-1]);

        return result;
    }
};

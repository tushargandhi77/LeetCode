class Solution {
public:
    double t[101][101];
    double solve(int poured,int i,int j){


        if(i < 0 || j < 0 || j > i ) return 0.0;

        if(t[i][j] != -1) return t[i][j];

        if(i == 0 && j == 0 ) return t[i][j] = (double)poured;


        double upper_left = (solve(poured,i-1,j-1) - 1)/2.0;
        double upper_right = (solve(poured,i-1,j) - 1)/2.0;

        if(upper_left < 0 ) upper_left = 0.0;
        if(upper_right < 0) upper_right = 0.0;

        return t[i][j] = upper_left + upper_right;

    }
    double champagneTower(int poured, int query_row, int query_glass) {
       for(int i = 0;i<101;i++){
        for(int j = 0;j<101;j++){
            t[i][j] = -1;
        }
       }
        return min(1.0,solve(poured,query_row,query_glass));
    }
};

class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> t(101,vector<double>(101));

        t[0][0] = (double)poured;

        for(int row = 0;row<=query_row;row++){
            for(int col = 0;col<=row;col++){
                double extra = (t[row][col] - 1)/2.0;

                if(extra > 0){
                    t[row+1][col+1] += extra;
                    t[row+1][col] += extra;
                }
            }
        }

        return min(1.0,t[query_row][query_glass]);
    }
};

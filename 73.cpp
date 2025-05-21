class Solution {
public:
    int m,n;
    void transform(int x,int y,vector<vector<int>>& matrix){
        for(int j = 0;j<n;j++){
            matrix[x][j] = 0;
        }
        for(int i = 0;i<m;i++){
            matrix[i][y] = 0;
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
        set<pair<int,int>> st;
        m = matrix.size();
        n = matrix[0].size();
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(matrix[i][j] == 0){
                    st.insert({i,j});
                }
            }
        }

        for(auto it: st){
            transform(it.first,it.second,matrix);
        }
    }
};

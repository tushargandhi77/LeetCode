class Solution {
public:
    int n;

    void SolveDiag(int row,int col,vector<vector<int>>& grid,bool reverse){
        vector<int> vec;

        int i = row;
        int j = col;

        while(i < n && j < n){
            vec.push_back(grid[i][j]);
            i++;
            j++;
        }

        if(reverse == true){
            sort(begin(vec),end(vec),greater<int>());
        }
        else{
            sort(begin(vec),end(vec));
        }

        i = row;
        j = col;

        for(int val: vec){
            grid[i][j] = val;
            i++;
            j++;
        }
    }
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
         n = grid.size();

         for(int row = 0;row<n;row++){
            SolveDiag(row,0,grid,true);
         }

         for(int col = 1;col<n;col++){
            SolveDiag(0,col,grid,false);
         }

         return grid;
    }
};

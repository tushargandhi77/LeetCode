class Solution {
public:
    vector<vector<int>> directions{{0,1},{0,-1},{1,0},{-1,0}};

    void DFS(int i,int j, vector<vector<int>>& heights,int prev,vector<vector<bool>>& visited){
        if(i < 0 || i >= heights.size() || j < 0 || j >= heights[0].size()){
            return;
        }

        if(heights[i][j] < prev || visited[i][j] == true) return;

        visited[i][j] = true;

        for(auto& dir: directions){
            int i_ = i + dir[0];
            int j_ = j + dir[1];

            DFS(i_,j_,heights,heights[i][j],visited);
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<bool>> pacificVisited(m,vector<bool>(n,false));
        vector<vector<bool>> atlanticVisited(m,vector<bool>(n,false));

        for(int j = 0;j<n;j++){
            DFS(0,j,heights,INT_MIN,pacificVisited);
            DFS(m-1,j,heights,INT_MIN,atlanticVisited);
        }

        for(int i = 0;i<m;i++){
            DFS(i,0,heights,INT_MIN,pacificVisited);
            DFS(i,n-1,heights,INT_MIN,atlanticVisited);
        }

        vector<vector<int>> result;

        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(pacificVisited[i][j] && atlanticVisited[i][j]){
                    result.push_back({i,j});
                }
            }
        }

        return result;
    }
};

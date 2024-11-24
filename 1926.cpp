class Solution {
public:
    vector<vector<int>> dir{{1,0},{-1,0},{0,1},{0,-1}};
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size();
        int n = maze[0].size();

        queue<pair<int,int>> que;
        que.push({entrance[0],entrance[1]});
        maze[entrance[0]][entrance[1]] = '+';

        int step = 0;

        while(!que.empty()){
            int N = que.size();

            while(N--){
                pair<int,int> it = que.front();
                que.pop();

                int i = it.first;
                int j = it.second;

                if(it != make_pair(entrance[0],entrance[1]) && (i == 0 || i == m-1 || j == 0 || j== n-1)) return step;

                for(auto& vec: dir){
                    int x = i + vec[0];
                    int y = j + vec[1];

                    if(x >= 0 && x < m && y >= 0 && y < n && maze[x][y] == '.'){
                        que.push({x,y});
                        maze[x][y] = '+';
                    }
                }
            }
            step++;
        }
        return -1;
    }
};

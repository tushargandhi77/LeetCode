class Solution {
public:
    int n;
    pair<int,int> getcordinate(int num){
        int rc = (num-1)/n;
        int rb = (n-1) - rc;

        int col = (num-1) % n;

        if((n % 2 == 1 && rb % 2 == 1) || (n % 2 == 0 && rb % 2 == 0)){
            col = (n-1) - col;
        }

        return {rb,col};
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        n = board.size();

        queue<int> que;
        vector<vector<bool>> visited(n,vector<bool>(n,false));

        que.push(1);
        visited[n-1][0] = true;
        
        int steps = 0;
        while(!que.empty()){
            int N = que.size();
            while(N--){
                int node = que.front();
                que.pop();

                if(node == n*n) return steps;

                for(int k = 1;k<=6;k++){
                    int val = k + node;

                    if(val > n*n){
                        break;
                    }

                    pair<int,int> cor = getcordinate(val);

                    int x = cor.first;
                    int y = cor.second;
                    
                    if(visited[x][y]) continue;

                    visited[x][y] = true;

                    if(board[x][y] == -1){
                        que.push(val);
                    }
                    else{
                        que.push(board[x][y]);
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};

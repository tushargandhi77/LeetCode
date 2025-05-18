class Solution {
public:
    vector<string> columnStates;
    int M = 1e9+7;
    vector<vector<int>> t;
    void generateColumnStates(string curr,char prevChar,int l,int m){
        if(l == m){
            columnStates.push_back(curr);
            return;
        }

        for(char ch: {'R','G','B'}){
            if(ch == prevChar) continue;

            generateColumnStates(curr+ch,ch,l+1,m);
        }

    }
    int solve(int remainCols,int prevIdx,int m){
        if(remainCols == 0) return 1;

        if(t[remainCols][prevIdx] != -1) return t[remainCols][prevIdx];

        int ways = 0;
        string prevState = columnStates[prevIdx];

        for(int i = 0;i<columnStates.size();i++){
            if(i == prevIdx) continue;
            string currState = columnStates[i];
            bool valid = true;

            for(int j = 0;j<m;j++){
                if(prevState[j] == currState[j]){
                    valid = false;
                    break;
                }
            }
            if(valid){
                ways = (ways + solve(remainCols-1,i,m)) % M;
            }
        }
        return t[remainCols][prevIdx] = ways;
    }
    int colorTheGrid(int m, int n) {
        // generate column states
        generateColumnStates("",'#',0,m);
        t = vector<vector<int>>(n+1,vector<int>(columnStates.size()+1,-1));
        // step 2 
        int result = 0;
        for(int i = 0;i<columnStates.size();i++){
            result = (result + solve(n-1,i,m))%M;
        }
        return result;
    }
};

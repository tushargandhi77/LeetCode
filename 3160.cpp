class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        int n = queries.size();
        vector<int> result(n);

        unordered_map<int,int> colorMp;


        unordered_map<int,int> ballMp;

        for(int i = 0;i<n;i++){
            int ball = queries[i][0];
            int color = queries[i][1];

            if(ballMp.count(ball)){
                int prevColor = ballMp[ball];
                colorMp[prevColor]--;

                if(colorMp[prevColor] == 0){
                    colorMp.erase(prevColor);
                }
            }

            ballMp[ball] = color;
            colorMp[color]++;

            result[i] = colorMp.size();
        }
        return result;
    }
};

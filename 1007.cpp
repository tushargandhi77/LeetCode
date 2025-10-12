class Solution {
public:
    int findval(vector<int>& tops, vector<int>& bottoms,int val){
        int n = tops.size();
        int topsstep = 0;
        int bottomsstep = 0;
        for(int i = 0;i<n;i++){
            if(tops[i] != val && bottoms[i] != val) return -1;
            else if(tops[i] != val) topsstep++;
            else if(bottoms[i] != val) bottomsstep++;
        }
        return min(topsstep,bottomsstep);
    }
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int result = INT_MAX;

        for(int i = 1;i<=6;i++){
            int steps = findval(tops,bottoms,i);
            if(steps != -1){
                result = min(steps,result);
            }
        }

        return result == INT_MAX ? -1 : result;
    }
};

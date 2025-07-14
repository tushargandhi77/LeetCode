class Solution {
public:
    int solve(int left,int right,vector<int>& cuts,vector<vector<int>>& t){
        if(right - left < 2) return 0;

        if(t[left][right] != -1) return t[left][right];

        int result = INT_MAX;
        for(int i = left+1;i<=right-1;i++){
            int cost = (cuts[right] - cuts[left]) + solve(left,i,cuts,t) + solve(i,right,cuts,t);

            result = min(cost,result);
        }

        return t[left][right] = result;
    }
    int minCost(int n, vector<int>& cuts) {
        sort(begin(cuts),end(cuts));

        cuts.insert(begin(cuts),0);
        cuts.push_back(n);

        vector<vector<int>> t(103,vector<int>(103,-1));

        return solve(0,cuts.size()-1,cuts,t);
    }
};

// TC :- O(cuts.size()^3)

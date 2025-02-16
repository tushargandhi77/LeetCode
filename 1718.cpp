class Solution {
public:
    bool solve(int idx,int n,vector<int>& result,vector<bool>& used){
        if(idx >= result.size()) return true;

        if(result[idx] != -1){
            return solve(idx+1,n,result,used);
        }

        for(int num = n;num>=1;num--){
            if(used[num]) continue;

            result[idx] = num;
            used[num] = true;

            if(num == 1){
                if(solve(idx+1,n,result,used)==true){
                    return true;
                }
            }
            else{
                int j = result[idx] + idx;

                if(j < result.size() && result[j] == -1){
                    result[j] = num;
                    if(solve(idx+1,n,result,used) == true){
                        return true;
                    }
                    result[j] = -1;
                }
            }

            used[num] = false;
            result[idx] = -1; 

        }
        return false;
    }
    vector<int> constructDistancedSequence(int n) {
        vector<int> result(2*n-1,-1);
        vector<bool> used(n+1,false);

        solve(0,n,result,used);

        return result;
    }
};

class Solution {
public:
    int t[20001][4];
    int Helper(vector<int>& subarray,int count,int i,int k){
        if(count == 0) return 0;
        if(i >= subarray.size()) return INT_MIN;

        if(t[i][count]!=-1) return t[i][count];

        int take_i = subarray[i] + Helper(subarray,count-1,i+k,k);
        int not_take = Helper(subarray,count,i+1,k);

        return t[i][count] = max(take_i,not_take);
    }
    void solve(vector<int>& subarray,int count,int i,int k,vector<int>& result){
        if(count == 0) return;

        if(i>=subarray.size()) return;

        int take_i = subarray[i] + Helper(subarray,count-1,i+k,k);
        int not_take_i = Helper(subarray,count,i+1,k);

        if(take_i>=not_take_i){
            result.push_back(i);
            solve(subarray,count-1,i+k,k,result);
        }
        else{
            solve(subarray,count,i+1,k,result);
        }
    }
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        memset(t,-1,sizeof(t));
        vector<int> subarray;
        int i = 0;
        int j = 0;
        int currsum = 0;
        while(j<nums.size()){
            currsum += nums[j];

            if(j-i+1 == k){
                subarray.push_back(currsum);
                currsum -= nums[i];
                i++;
            }
            j++;
        }
        vector<int> result;
        solve(subarray,3,0,k,result);
        return result;
    }
};

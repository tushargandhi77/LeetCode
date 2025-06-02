class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();

        vector<int> Count(n,1);


        for(int i = 1;i<n;i++){
            if(ratings[i] > ratings[i-1]){
                Count[i] = max(Count[i],Count[i-1]+1);
            }
        }

        for(int i = n-2;i>=0;i--){
            if(ratings[i] > ratings[i+1]){
                Count[i] = max(Count[i],Count[i+1]+1);
            }
        }
        int result = 0;

        for(int i = 0;i<n;i++){
            result += Count[i];
        }

        return result;
    }
};

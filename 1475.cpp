class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int  n = prices.size();
        vector<int> answer(n,0);
        answer[n-1] = prices[n-1];
        for(int i = 0;i<n-1;i++){
            int j = i+1;
            while(j<n && prices[j]>prices[i]){
                j++;
            }
            if(j >= n){
                answer[i] = prices[i];
                continue;
            }
            answer[i] = prices[i] - prices[j];
        }
        return answer;
    }
};

class Solution {
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n = wt.size();
        vector<vector<int>> vec(n);
        
        for(int i = 0;i<n;i++){
            int v = val[i];
            int w = wt[i];
            
            
            vec[i] = {v,w};
        }
        
        sort(begin(vec),end(vec),[](vector<int>& p1,vector<int>& p2){
            return (1.0*p1[0]/p1[1]) > (1.0 * p2[0]/p2[1]);
        });
        
        double result = 0.0;
        
        for(int i = 0;i<n;i++){
            double v = vec[i][0];
            double w = vec[i][1];
            
            if(w <= capacity){
                result += (double)v;
                capacity -= w;
            }
            else{
                result += (1.0 * v / w) * capacity;
                break;
            }
        }
        
        return result;
    }
};

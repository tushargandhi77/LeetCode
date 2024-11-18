class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();

        vector<int> result(n,0);
        if(k==0) return result;

        for(int i = 0;i<n;i++){
            if(k>0){
                int ele = 0;
                int temp = k;
                int j = i==n-1?0:i+1;
                while(temp > 0){
                    ele += code[j];
                    j = (j+1)%n;
                    temp --;
                }
                result[i] = ele;
            }
            else{
                int ele = 0;
                int temp = abs(k);
                int j = i == 0 ? n-1 : i-1;
                while(temp--){
                    ele += code[j];
                    if(j==0) j = n;
                    j = (j-1)%n;
                }
                result[i] = ele;
            }
        }
        return result;
    }
};

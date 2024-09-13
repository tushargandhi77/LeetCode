class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {

        vector<int> result;
        for(auto& vec: queries){
            int a = vec[0];
            int b = vec[1];
            if(a==b){
                result.push_back(arr[a]);
                continue;
            }
            int c = arr[a];
            for(int i = a+1;i<=b;i++){
                c = c ^ arr[i];
            }
            result.push_back(c);
        }
        return result;
    }
};

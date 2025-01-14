class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();

        vector<bool> APrefix(n+1,false);
        vector<bool> BPrefix(n+1,false);

        vector<int> result(n);
        for(int i = 0;i<n;i++){
            APrefix[A[i]] = true;
            BPrefix[B[i]] = true;
            int count = 0;
            for(int i = 1;i<=n;i++){
                if(APrefix[i] == true && BPrefix[i] == true) count++;
            }
            result[i] = count;
        }
        return result;
    }
};

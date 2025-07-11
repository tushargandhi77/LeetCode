// Recusion + Memo

class Solution {
public:
    int t[501][501];
    int solve(int i,int j,vector<int>&nums1,vector<int>& nums2){
        if(i >= nums1.size() || j >= nums2.size()) return 0;

        if(t[i][j] != -1) return t[i][j];

        if(nums1[i] == nums2[j]){
            return t[i][j] = 1 + solve(i+1,j+1,nums1,nums2);
        }

        int option1 = solve(i+1,j,nums1,nums2);
        int option2 = solve(i,j+1,nums1,nums2);

        return t[i][j] = max(option1,option2);
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        memset(t,-1,sizeof(t));
        return solve(0,0,nums1,nums2);
    }
};


// Bu

class Solution {
public:
    
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
       int n1 = nums1.size();
       int n2 = nums2.size();


       vector<vector<int>> t(n1+1,vector<int>(n2+1,0));

       for(int i = 1;i<=n1;i++){
        for(int j = 1;j<=n2;j++){
                if(nums1[i-1] == nums2[j-1]){
                    t[i][j] = 1 + t[i-1][j-1];
                }
                else{
                    t[i][j] = max(t[i-1][j],t[i][j-1]);
                }
            }
       }

       return t[n1][n2];
    }
};

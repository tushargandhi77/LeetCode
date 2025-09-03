// M1

class Solution {
public:
    int t[501][501];
    int solve(int i,int j,vector<int>& nums1, vector<int>& nums2){
        if(i >= nums1.size() || j >= nums2.size()){
            return -1e9;
        }

        if(t[i][j] != -1) return t[i][j];

        int val = nums1[i]*nums2[j];

        int take_i_j = nums1[i]*nums2[j] + solve(i+1,j+1,nums1,nums2);

        int take_i = solve(i,j+1,nums1,nums2);

        int take_j = solve(i+1,j,nums1,nums2);

        return t[i][j] = max({val,take_i_j,take_i,take_j});
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        memset(t,-1,sizeof(t));
        return solve(0,0,nums1,nums2);
    }
};

// M2 

class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n = s.length();
        string result = string(n,'0');
        
        int count_1 = 0;

        for(char ch:s){
            if(ch=='1') count_1++;
        }

        result[n-1] = '1';
        count_1--;

        int i = 0;
        while(count_1--){
            result[i] = '1';
            i++;
        }

        return result;
    }
};

// M3

class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n = s.length();
        string result = string(n,'0');
        
        int count_1 = count(s.begin(),s.end(),'1');

        int i = 0;
        while(count_1 > 1){
            result[i] = '1';
            i++;
            count_1--;
        }

        result[n-1] = '1';

        return result;
    }
};

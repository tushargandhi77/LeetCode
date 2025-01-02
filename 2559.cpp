class Solution {
public:
    bool isvowel(char& a,char& b){
        return ((a=='a'||a=='e'||a=='o'||a=='i'||a=='u')&&(b=='a'||b=='e'||b=='o'||b=='i'||b=='u'));
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();

        vector<int> nums(n);
        string temp = words[0];
        if(isvowel(temp[0],temp[temp.length()-1])){
            nums[0] = 1;
        }
        else{
            nums[0] = 0;
        }

        for(int i = 1;i<n;i++){
            temp = words[i];
            if(isvowel(temp[0],temp[temp.length()-1])){
                nums[i] = nums[i-1] + 1;
            }
            else{
                nums[i] = nums[i-1];
            }
        }
        vector<int> result;
        for(auto& vec: queries){
            int start = vec[0];
            int end = vec[1];

            if(start == 0){
                result.push_back(nums[end]);
                continue;
            }
            result.push_back((nums[end]-nums[start-1]));
        }
        return result;
    }
};

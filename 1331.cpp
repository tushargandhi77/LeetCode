class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        unordered_map<int,int> mp;
        set<int> st(begin(arr),end(arr));

        int rank = 1;
        for(auto& n:st){
            mp[n] = rank;
            rank++;
        }

        for(int i = 0;i<arr.size();i++){
            arr[i] = mp[arr[i]];
        }
        return arr;
    }
};

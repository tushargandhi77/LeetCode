class Solution {
public:

    map<pair<int,int>,int> mp;
    int solve(int idx,int prev,vector<int>& arr1, vector<int>& arr2){
        if(idx >= arr1.size()) return 0;

        if(mp.count({idx,prev})) return mp[{idx,prev}];

        int option1 = 1e9+1;

        if(arr1[idx] > prev){
            option1 = solve(idx+1,arr1[idx],arr1,arr2);
        }

        int option2 = 1e9+1;

        auto it = upper_bound(begin(arr2),end(arr2),prev);

        if(it != end(arr2)){
            int j = it - begin(arr2);
            option2 = 1 + solve(idx+1,arr2[j],arr1,arr2);
        }

        return mp[{idx,prev}] = min(option1,option2);
    }
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(begin(arr2),end(arr2));

        int result  = solve(0,INT_MIN,arr1,arr2);

        return result == 1e9+1 ? -1 : result;
    }
};

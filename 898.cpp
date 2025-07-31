class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        int n = arr.size();
        unordered_set<int> result;
        unordered_set<int> curr;
        unordered_set<int> prev;

        for(int i = 0;i<n;i++){
            for(int num: prev){
                curr.insert(num|arr[i]);
                result.insert(num|arr[i]);
            }
            curr.insert(arr[i]);
            result.insert(arr[i]);
            prev = curr;
            curr.clear();

        }

        return result.size();
    }
};

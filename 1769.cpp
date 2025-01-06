class Solution {
public:
    vector<int> minOperations(string boxes) {
        unordered_set<int> st;
        int n = boxes.length();
        vector<int> result(n);


        for(int i = 0;i<n;i++){
            if(boxes[i]=='1'){
                st.insert(i);
            }
        }

        for(int i = 0;i<n;i++){
            int count = 0;
            for(int v: st){
                count += abs(v-i);
            }
            result[i] = count;
        }
        return result;
    }
};

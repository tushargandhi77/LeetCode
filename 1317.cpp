class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        for(int i = 1;i<n;i++){
            int num1 = i;
            int num2 = n - i;

            string s = to_string(num1) + "_" + to_string(num2);

            if(s.find('0') == string::npos){
                return {num1,num2};
            }
        }
        return{};
    }
};

class Solution {
public:
    int minOperations(string s) {
        int start_with_0 = 0; // 010101...
        int start_with_1 = 0; // 101010...

        for(int i = 0;i<s.length();i++){
            if(i%2 == 0){//Even
                if(s[i] == '0'){
                    start_with_1++;
                }
                else{
                    start_with_0++;
                }
            }
            else{//ODD
                if(s[i] == '1'){
                    start_with_1++;
                }
                else{
                    start_with_0++;
                }
            }
        }   

        return min(start_with_0,start_with_1);
    }
};

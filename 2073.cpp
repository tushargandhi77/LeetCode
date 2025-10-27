class Solution {
public:
    int countones(string & s){
        int count = 0;
        for(char& ch: s){
            if(ch == '1') count++;
        }
        return count;
    }
    int numberOfBeams(vector<string>& bank) {
        int result = 0;
        int prev = 0;

        for(string& s: bank){
            int count = countones(s);
            if(count != 0){
                result += prev*count;
                prev = count;
            }
        }

        return result;
    }
};

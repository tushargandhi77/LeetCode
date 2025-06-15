// Method 1 :->

class Solution {
public:
    int maxDiff(int num) {
        string str1 = to_string(num);
        string str2 = str1;

        int idx = str1.find_first_not_of('9');

        if(idx != string::npos){
            char ch = str1[idx];
            replace(begin(str1),end(str1),ch,'9');
        }
        
        int idx1 = -1;
        for(int i = 0;i<str2.length();i++){
            if(str2[i] != '1' && str2[i] != '0'){
                idx1 = i;
                break;
            }
        }

        if(idx1 > 0 && idx1 != string::npos){
            char ch = str2[idx1];
            replace(begin(str2),end(str2),ch,'0');
        }
        if(idx1 == 0 && idx1 != string::npos){
            char ch = str2[idx1];
            replace(begin(str2),end(str2),ch,'1');
        }

        
        return stoi(str1) - stoi(str2);
    }
};

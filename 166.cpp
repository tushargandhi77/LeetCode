class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator == 0) return "0";

        string result = "";
        if((long long)numerator*denominator < 0){
            result += "-";
        }

        long long absnumerator = labs(numerator);
        long long absdenomiator = labs(denominator);

        long long integerDiv = absnumerator / absdenomiator;
         
        result += to_string(integerDiv);

        long long remain = absnumerator % absdenomiator;
        
        if(remain == 0) return result;

        result += '.';

        unordered_map<int,int> mp;

        while(remain != 0){
            if(mp.count(remain)){
                result.insert(mp[remain],"(");
                result+=")";
                break;
            }

            mp[remain] = result.length();
            
            remain *= 10;
            int digit = remain/absdenomiator;
            result += to_string(digit);

            remain = (remain % absdenomiator);
        }

        return result;

    }
};

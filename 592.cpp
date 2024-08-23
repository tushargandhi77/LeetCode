
class Solution {
public:
    string fractionAddition(string expression) {
         int num = 0;
         int dem = 1;

         int i = 0;
         int n = expression.length();
         while(i<n){
            int currnum = 0;
            int currdem = 0;

            bool isNeg = (expression[i] == '-');
            if(expression[i] == '+' || expression[i] == '-'){
                i++;
            }
            while(i<n && isdigit(expression[i])){
                int val = expression[i] - '0';
                currnum = (currnum*10) + val;
                i++;
            }
            i++;
            if(isNeg == true) currnum *= -1;
            while(i < n && isdigit(expression[i])){
                int val = expression[i] - '0';
                currdem = (currdem * 10 ) + val;
                i++;
            }

            num = num * currdem + currnum * dem;
            dem = dem * currdem;
         }
         int GCD = abs(__gcd(num,dem));
         num /= GCD;
         dem /= GCD;

         return to_string(num) + "/" + to_string(dem);
    }
};

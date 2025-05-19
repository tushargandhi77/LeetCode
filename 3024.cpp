class Solution {
public:
    string triangleType(vector<int>& nums) {
        string result = "";

        int a = nums[0];
        int b = nums[1];
        int c = nums[2];

        if((a+b)>c && (a+c)>b && (b+c)>a){
            if(a == b && b==c && c == a){
                result = "equilateral";
            }
            else if(a != b && b != c && c != a){
                result = "scalene";
            }
            else{
                result = "isosceles";
            }
        }
        else{
            return "none";
        }

        return result;
    }
};

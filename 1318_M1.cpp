class Solution {
public:
    int minFlips(int a, int b, int c) {
        int flip = 0;

        while(a != 0 || b != 0 || c != 0){
            int a_lst = (a & 1);
            int b_lst = (b & 1);
            int c_lst = (c & 1);

            if(c_lst == 1){
                if(a_lst == 0 && b_lst == 0){
                    flip++;
                }
            }
            else if(c_lst == 0){
                if(a_lst == 1 ) flip++;
                if(b_lst == 1) flip++;
            }

            a >>= 1;
            b >>= 1;
            c >>= 1;
        }
        return flip;
    }
};

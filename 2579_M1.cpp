class Solution {
public:
    long long coloredCells(int n) {
        long long cell = 1;
        if(n == 1) return 1;

        int t =  1;

        while(t <= n){
            cell += 4*(t-1);
            t++;
        }
        return cell;
    }
};

class Solution {
public:
    int passThePillow(int n, int time) {
        n = n-1;
        int t = time/n;

        if(t % 2 != 0){
            int rem = time % n;

            return (n - rem)+1;
        }

        return (time%n)+1;


    }
};

class Solution {
public:
    int passThePillow(int n, int time) {
        int idx = 1;
        int dir = 1;

        while(time > 0){
            if((idx+dir >= 1) && (idx+dir <= n)){
                time--;
                idx += dir;
            }
            else{
                dir *= -1;
            }
        }

        return idx;
    }
};

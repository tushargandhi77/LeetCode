class Solution {
public:
    int maxDistance(string s, int k) {
        int east = 0;
        int west = 0;
        int north = 0;
        int south = 0;

        int result = INT_MIN;
        for(int i = 0;i<s.length();i++){
            if(s[i] == 'E') east++;
            if(s[i] == 'W') west++;
            if(s[i] == 'N') north++;
            if(s[i] == 'S') south++;

            int ManD = abs(east - west) + abs(north-south);
            int steps = (i+1);

            int wasted = steps - ManD;

            int extra = 0;
            if(wasted != 0){
                extra = min(2*k,wasted);
            }

            int finalManD = ManD + extra;

            result = max(result,finalManD);
        }

        return result;
    }
};

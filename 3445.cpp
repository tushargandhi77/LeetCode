class Solution {
public:

    int getState(int count_a,int count_b){
        int parity_a = count_a % 2; // odd -> 1 even -> 0 parity
        int parity_b = count_b % 2;

        if(parity_a == 0 && parity_b == 0) return 0;
        if(parity_a == 0 && parity_b == 1) return 1;
        if(parity_a == 1 && parity_b == 0) return 2;
        if(parity_a == 1 && parity_b == 1) return 3;

        return -1;
    }
    int maxDifference(string s, int k) {
        int n = s.length();
        int result = INT_MIN;

        for(char a = '0' ;a<='4'; a++){
            for(char b = '0' ; b <='4';b++){
                if(a==b) continue;

                // state min previous a _ b
                vector<int> stateMinPrev_a_b(4,INT_MAX); 

                int count_a = 0;
                int count_b = 0;

                // count of a and b till prev index l
                int prev_a = 0;
                int prev_b = 0;

                // sliding window

                int l = -1;
                int r = 0;

                while(r < n ){
                    count_a += (s[r] == a) ? 1 : 0;
                    count_b += (s[r] == b) ? 1 : 0;

                    while((r-l) >= k && count_b - prev_b >= 2 && count_a - prev_a >=1){
                        int leftstate = getState(prev_a,prev_b);
                        stateMinPrev_a_b[leftstate] = min(stateMinPrev_a_b[leftstate],prev_a - prev_b);
                        l++;

                        prev_a += (s[l] == a) ? 1 : 0;
                        prev_b += (s[l] == b) ? 1 : 0;
                    }

                    int rightState = getState(count_a,count_b);
                    int bestLeftState = rightState ^ 2;
                    int bestMinDiffValue = stateMinPrev_a_b[bestLeftState];
                    if(bestMinDiffValue != INT_MAX){
                        result = max(result,(count_a - count_b) - bestMinDiffValue);
                    }
                    r++;
                }
            }
        }
        return result;
    }
};

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int m = spells.size();
        int n = potions.size();

        sort(begin(potions),end(potions));
        vector<int> result(m);
        int maxPotion = potions[n-1];
        for(int i = 0;i<m;i++){
            long long val = ceil((1.0*success)/spells[i]);
            

            if(val > maxPotion){
                result[i] = 0;
                continue;
            }

            int idx = lower_bound(begin(potions),end(potions),val) - begin(potions);

            result[i] = (n-idx);

        }
        return result;
    }
};

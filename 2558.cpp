class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        long long result = 0;
        priority_queue<int> pq;
        for(int& gift: gifts){
            pq.push(gift);
        }
        while(k--){
            int pile = pq.top();
            pq.pop();

            int new_pile = (int)floor(sqrt(pile));
            pq.push(new_pile);
        }

        while(!pq.empty()){
            result += pq.top();
            pq.pop();
        }
        return result;
    }
};

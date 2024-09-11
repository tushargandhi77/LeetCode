class Solution {
public:
    int minBitFlips(int start, int goal) {
     bitset<32> start_bit(start);
     bitset<32> goal_bit(goal);
     bitset<32> result = start_bit^goal_bit;
     return result.count();
    }
};

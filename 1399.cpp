class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map<int,int> mp;

        for(int i = 1;i<=n;i++){
            int num = i;
            int sum = 0;
            while(num > 0){
                int d = num % 10;
                sum += d;
                num /= 10;
            }
            mp[sum]++;
        }

        int max = 0;
        int count = 0;
        for(auto it: mp){
            if(it.second > max){
                max = it.second;
            }
        }

        for(auto it: mp){
            if(it.second == max) count++;
        }

        return count;
    }
};

class Solution {
public:
    int countsum(int n){
        int sum = 0;
        while(n > 0){
            sum += n % 10;
            n/=10;
        }

        return sum;
    }
    int countLargestGroup(int n) {
        unordered_map<int,int> mp;
        int count = 0;
        int maxVal = 0;

        for(int i = 1;i<=n;i++){
            int sum = countsum(i);
            mp[sum]++;
            
            if(mp[sum] == maxVal){
                count++;
            }
            else if(mp[sum] > maxVal){
                maxVal = mp[sum];
                count = 0;
            }
        }

        return count+1;
    }
};

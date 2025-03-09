class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        vector<int> resultant = colors;

        for(int i = 0;i<k-1;i++){
            resultant.push_back(colors[i]);
        }

        int n = resultant.size();

        int result = 0;

        int i = 0;
        int j = 1;

        while(j < n){
            if(resultant[j-1] == resultant[j]){
                i = j;
            }
            if((j-i+1) == k){
                i++;
                result++;
            }

            j++;
        }
        return result;
    }
};

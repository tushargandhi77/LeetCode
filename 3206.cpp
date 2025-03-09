class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        // 0 1 0 0 1 0 1

        vector<int> resultant = colors;
        for(int i = 0;i<2;i++){
            resultant.push_back(colors[i]);
        }

        int n = resultant.size();

        int i = 0;
        int j = 1;

        int result = 0;
        while(j < n){
            if(resultant[j] == resultant[j-1]){
                i = j;
            }

            if(j-i+1 == 3){
                i++;
                result++;
            }
            j++;
        }
        return result;
    }
};

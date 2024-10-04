class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        vector<pair<int,int>> pr;

        int n = skill.size();
        sort(begin(skill),end(skill));
        int check = skill[0] + skill[n-1];
        for(int i = 0;i<n/2;i++){
            int sum = skill[i] + skill[n-i-1];
            if(check != sum) return -1;

            pr.push_back({skill[i],skill[n-i-1]});
        }

        long long result = 0;

        for(auto&x : pr){
            result += x.first*x.second;
        }
        return result;
    }
};

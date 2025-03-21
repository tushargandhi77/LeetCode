class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        int n = recipes.size();
        vector<string> result;

        unordered_set<string> st(begin(supplies),end(supplies));
        unordered_set<string> res;
        int count = n;
        while(count--){
        for(int i = 0;i<n;i++){
            bool ismade = true;

            for(int j = 0;j<ingredients[i].size();j++){
                if(!st.count(ingredients[i][j])){
                    ismade = false;
                    break;
                }
            }
            if(ismade && !res.count(recipes[i])){
                result.push_back(recipes[i]);
                res.insert(recipes[i]);
                st.insert(recipes[i]);
            }
        }
        }

        


        return result;
    }
};

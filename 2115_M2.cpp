class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        int n = recipes.size();

        vector<string> result;
        vector<bool> cooked(n,false);

        unordered_set<string> st(begin(supplies),end(supplies));

        int count = n;

        while(count--){
            for(int i = 0;i<n;i++){
                bool iscook = true;
                if(cooked[i] == true) continue;
                for(int j = 0;j<ingredients[i].size();j++){
                    if(!st.count(ingredients[i][j])){
                        iscook = false;
                        break;
                    }
                }
                if(iscook){
                    result.push_back(recipes[i]);
                    st.insert(recipes[i]);
                    cooked[i] = true;
                }
            }
        }

        return result;
    }
};

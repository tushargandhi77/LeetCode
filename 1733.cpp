class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        unordered_set<int> sadUsers;

        for(auto& friends: friendships){
            int u = friends[0] - 1;
            int v = friends[1] - 1;

            unordered_set<int> st(begin(languages[u]),end(languages[u]));

            bool cantalk = false;
            for(int& node: languages[v]){
                if(st.count(node)){
                    cantalk = true;
                    break;
                }
            }

            if(!cantalk){
                sadUsers.insert(u);
                sadUsers.insert(v);
            }
        }

        vector<int> language(n+1,0);
        int maxtaught = 0;

        for(int val: sadUsers){
            for(int lang: languages[val]){
                language[lang]++;
                maxtaught = max(maxtaught,language[lang]);
            }
        }

        return sadUsers.size() - maxtaught;

    }
};

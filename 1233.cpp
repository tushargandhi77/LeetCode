class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        unordered_set<string> st(begin(folder),end(folder));
        vector<string> result;

        for(string& fol:folder){
            bool isSubFolder = false;

            string tempFolder = fol;
            while(!fol.empty()){
                size_t position = fol.find_last_of('/');

                fol = fol.substr(0,position);

                if(st.find(fol) != st.end()){
                    isSubFolder = true;
                    break;
                }
            }
            if(!isSubFolder){
                result.push_back(tempFolder);
            }
        }
        return result;
    }
};

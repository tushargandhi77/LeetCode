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


class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(begin(folder),end(folder));
        vector<string> result;
        result.push_back(folder[0]);

        for(int i = 1;i<folder.size();i++){
            string currfolder = folder[i];
            string lastfolder = result.back();
            lastfolder += "/";

            if(currfolder.find(lastfolder)  != 0){
                result.push_back(currfolder);
            }
        }

        return result;
    }
};

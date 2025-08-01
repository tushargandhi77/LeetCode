class Solution {
public:
    struct Node{
        string val;
        string subFolder;
        unordered_map<string,Node*> children;
    };

    Node* getNode(string val){
        Node* temp = new Node();
        temp->val = val;
        temp->subFolder = "";

        return temp;
    }

    void insert(Node* root,vector<string>& path){
        for(auto& folder: path){
            if(!root->children.count(folder)){
                root->children[folder] = getNode(folder);
            }
            root = root->children[folder];
        }
    }

    string populateNodes(Node* root,unordered_map<string,int>& subFolderMap){
        vector<pair<string,string>> subFolderPaths;
        for(auto &[childName,child]: root->children){
            string subFolderResult = populateNodes(child,subFolderMap);
            subFolderPaths.push_back({childName,subFolderResult});
        }

        sort(begin(subFolderPaths),end(subFolderPaths));

        string completePath = "";

        for(auto& [childName,childPath] : subFolderPaths){
            completePath += "(" + childName + childPath + ")";
        }

        root->subFolder = completePath;

        if(!completePath.empty()){
            subFolderMap[completePath]++;
        }

        return completePath;
    }

    void removeDuplicates(Node* root,unordered_map<string,int>& subFolderMap){
        for(auto it = root->children.begin();it != root->children.end();){
            string childName = it->first;
            Node* child = it->second;

            if(!child->subFolder.empty() && subFolderMap[child->subFolder] > 1){
                it = root->children.erase(it);
            }
            else{
                removeDuplicates(child,subFolderMap);
                it++;
            }
        }
    }

    void constructResult(Node* root,vector<string>& path,vector<vector<string>>& result){
        for(auto& [childName,child] : root->children){
            path.push_back(childName);
            result.push_back(path);
            constructResult(child,path,result);
            path.pop_back();
        }
    }
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        Node* root = getNode("/");

        // 1
        for(auto& path: paths){
            insert(root,path);
        }   

        unordered_map<string,int> subFolderMap;
        //2
        populateNodes(root,subFolderMap);

        //3
        removeDuplicates(root,subFolderMap);

        vector<vector<string>> result;
        vector<string> path;
        //4
        constructResult(root,path,result);

        return result;
    }
};

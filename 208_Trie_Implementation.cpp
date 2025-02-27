class Trie {
public:
    struct trieNode{
        bool iswordEnd;
        trieNode* children[26];
    };

    trieNode* getnode(){
        trieNode* node = new trieNode();
        node->iswordEnd = false;

        for(int i = 0;i<26;i++){
            node->children[i] = NULL;
        }
        return node;
    }
    trieNode* root;
    Trie() {
        root = getnode();
    }
    
    void insert(string word) {
        trieNode* crawler = root;

        for(char& ch : word){
            int idx = ch - 'a';

            if(crawler->children[idx] == NULL){
                crawler->children[idx] = getnode();
            }

            crawler = crawler->children[idx];
        }
        crawler->iswordEnd = true;
    }
    
    bool search(string word) {
        trieNode* crawler = root;

        for(char&ch : word){
            int idx = ch - 'a';

            if(crawler->children[idx] == NULL) return false;

            crawler = crawler->children[idx];
        }

        if(crawler != NULL && crawler->iswordEnd == true){
            return true;
        }

        return false;
    }

    
    bool startsWith(string prefix) {
        trieNode* crawler = root;

        for(char& ch : prefix){
            int idx = ch-'a';

            if(crawler->children[idx] == NULL) return false;

            crawler = crawler->children[idx];
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

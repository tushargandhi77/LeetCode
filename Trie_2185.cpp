struct trieNode{
    trieNode* children[26];
    bool isEndOfWord;
};

trieNode* getNode(){
    trieNode* newNode = new trieNode();
    newNode->isEndOfWord = 0;
    for(int i = 0;i<26;i++){
        newNode->children[i] = NULL;
    }
    return newNode;
}

class Trie{
    public:
        trieNode* root;
        Trie(){
            root = getNode();
        }

        void insert(string word){
            trieNode* pCrawl = root;
            for(int i = 0;i<word.length();i++){
                int idx = word[i] - 'a';
                if(pCrawl->children[idx] == NULL){
                    pCrawl->children[idx] = getNode();
                }
                pCrawl = pCrawl->children[idx];
            }
            pCrawl->isEndOfWord = true;
        }

        bool search(string prefix){
            trieNode* pCrawl = root;
            for(int i = 0;i<prefix.length();i++){
                int idx = prefix[i] - 'a';
                if(pCrawl->children[idx] == NULL){
                    return false;
                }
                pCrawl = pCrawl->children[idx];
            }
            return true;
        }
};
class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int n = words.size();
        int count = 0;

        for(int i = 0;i<n;i++){
            Trie prefix;

            prefix.insert(words[i]);

            if(words[i].length() < pref.length()) continue;

            if(prefix.search(pref) == true) count++;
        }
        return count;
    }
};

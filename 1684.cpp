class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int mask = 0;
        for(char& ch: allowed){
            mask |= (1<<(ch-'a'));
        }
        int count = 0;
        for(string &word: words){
            bool allcharpresent = true;

            for(char &ch: word){
                if(((mask >> (ch-'a'))& 1) == 0){
                    allcharpresent = false;
                    break;
                }
                }
                if(allcharpresent){
                    count++;
            }
        }
        return count;
    }
};

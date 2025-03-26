class Solution {
public:
    int n;
    int t[1001][1001];
    bool ispredecessor(string& s1,string& s2){
        int m = s1.length();
        int n = s2.length();

        if(m >= n || (n-m) != 1) return false;

        int i = 0;
        int j = 0;

        while(j < n && i < m){
            if(s1[i] == s2[j]) i++;
            
            j++;
        }

        return i == m;
    }
    int lis(vector<string>& words,int curr_idx,int prev_idx){
        if(curr_idx >= n) return 0;
        
        if(t[prev_idx+1][curr_idx] != -1) return t[prev_idx+1][curr_idx];


        int take = 0;

        if(prev_idx == -1 || ispredecessor(words[prev_idx],words[curr_idx])){
            take =  1 + lis(words,curr_idx+1,curr_idx);
        }

        int not_take = lis(words,curr_idx+1,prev_idx);

        return t[prev_idx+1][curr_idx] = max(take,not_take);
    }
    int longestStrChain(vector<string>& words) {
        n = words.size();
        memset(t,-1,sizeof(t));
        auto lambda = [&](string& word1,string& word2){
            return word1.length() < word2.length();
        };
        sort(begin(words),end(words),lambda);

        return lis(words,0,-1);
    }
};

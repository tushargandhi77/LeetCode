class Solution {

public:
    char DFS(unordered_map<char,vector<char>> adj,char curr,vector<bool>& visited){
        visited[curr-'a'] = true;

        char minchar = curr;

        for(char& v: adj[curr]){
            if(!visited[v-'a']){
                minchar = min(minchar,DFS(adj,v,visited));
            }
        }
        return minchar;
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        unordered_map<char,vector<char>> adj;
        int n = s1.size();
        for(int i = 0;i<n;i++){
            int u = s1[i];
            int v = s2[i];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        string result;

        for(auto& ch: baseStr){
            vector<bool> visited(26,false);

            char minchar = DFS(adj,ch,visited);
            result.push_back(minchar);
        }
        return result;
    }
};


// Method 2 

class Solution {
public:

    char DFS(char ch,unordered_map<char,vector<char>>& adj,unordered_set<char>& st){
        st.insert(ch);

        char newchar = ch;
        for(char& c: adj[ch]){
            if(!st.count(c)){
                newchar = min(newchar,DFS(c,adj,st));
            }
        }

        return newchar;
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        unordered_map<char,vector<char>> adj;
        int n = s1.length();
        for(int i = 0;i<n;i++){
            adj[s1[i]].push_back(s2[i]);
            adj[s2[i]].push_back(s1[i]);
        }
        string result = "";
        for(char& ch: baseStr){
            unordered_set<char> st;
            char c = DFS(ch,adj,st);
            result.push_back(c);
        }

        return result;
    }
};

class Solution {
public:
    int N;
    void solve(string& tiles,string& curr,vector<bool>& used,unordered_set<string>& result){
        result.insert(curr);

        for(int i = 0;i<N;i++){
            if(used[i] == true) continue;

            used[i] = true;
            curr.push_back(tiles[i]);
            solve(tiles,curr,used,result);
            used[i] = false;
            curr.pop_back(); 
        }
    }
    int numTilePossibilities(string tiles) {
        N = tiles.size();
        unordered_set<string> result;

        vector<bool> used(N,false);
        string curr = "";
        solve(tiles,curr,used,result);
        
        return result.size() -1 ;
    }
};

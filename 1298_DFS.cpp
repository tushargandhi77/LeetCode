class Solution {
public:
    unordered_set<int> st;

    int DFS(int box,vector<bool>& visited,vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes){
        if(visited[box] == true) return 0;

        if(status[box] == 0){
            st.insert(box);
            return 0;
        }

        int candy = 0;

        visited[box] = true;
        candy += candies[box];

        for(int& newbox: containedBoxes[box]){
            candy += DFS(newbox,visited,status,candies,keys,containedBoxes);
        }

        for(int& key: keys[box]){
            status[key] = 1;
            if(st.count(key)){
                candy += DFS(key,visited,status,candies,keys,containedBoxes);
            }
        }

        return candy;
    }
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int candy = 0;
        int n = status.size();
        vector<bool> visited(n,false);


        for(int box: initialBoxes){
            candy += DFS(box,visited,status,candies,keys,containedBoxes);
        }

        return candy;
    }
};

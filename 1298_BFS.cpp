class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int candiesCollected = 0;

        unordered_set<int> visited;
        unordered_set<int> foundBoxes;

        queue<int> que;
        for(int& box: initialBoxes){
            foundBoxes.insert(box);
            if(status[box] == 1){
                que.push(box);
                visited.insert(box);
                candiesCollected += candies[box];
            }
        }

        while(!que.empty()){
            int box = que.front();
            que.pop();

            for(int &insidebox: containedBoxes[box]){
                foundBoxes.insert(insidebox);
                if(status[insidebox] == 1 && !visited.count(insidebox)){
                    que.push(insidebox);
                    visited.insert(insidebox);
                    candiesCollected += candies[insidebox];
                }
            }

            for(int& boxkey: keys[box]){
                status[boxkey] = 1;
                if(foundBoxes.count(boxkey)&& !visited.count(boxkey)){
                    que.push(boxkey);
                    visited.insert(boxkey);
                    candiesCollected += candies[boxkey];
                }
            }
        }

        return candiesCollected;
    }
};

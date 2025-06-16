// Method 1 :-> BFS

class Solution {
public:
    typedef pair<int,int> P;
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        map<int,vector<P>> TimeMeet;

        vector<bool> isknow(n,false);
        isknow[0] = true;
        isknow[firstPerson] = true;

        for(auto& meet: meetings){
            int Person1 = meet[0];
            int Person2 = meet[1];
            int  time = meet[2];

            TimeMeet[time].push_back({Person1,Person2});
        }

        for(auto& it: TimeMeet){
            int time = it.first;
            auto person = it.second;

            unordered_map<int,vector<int>> adj;
            queue<int> que;
            unordered_set<int> alreadyknown;

            for(auto& it: person){
                int Person1 = it.first;
                int Person2 = it.second;

                adj[Person1].push_back(Person2);
                adj[Person2].push_back(Person1);

                if(isknow[Person1] && !alreadyknown.count(Person1)){
                    que.push(Person1);
                    alreadyknown.insert(Person1);
                }

                if(isknow[Person2] && !alreadyknown.count(Person2)){
                    que.push(Person2);
                    alreadyknown.insert(Person2);
                }
            }

            while(!que.empty()){
                int person = que.front();
                que.pop();

                for(int& nextperson: adj[person]){
                    if(isknow[nextperson] == false){
                        que.push(nextperson);
                        isknow[nextperson] = true;
                    }
                }
            }
        }

        vector<int> result;

        for(int i = 0;i<n;i++){
            if(isknow[i] == true){
                result.push_back(i);
            }
        }

        return result;
    }
};

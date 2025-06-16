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


// Method 2 :-> Direct BFS

class Solution {
public:
    typedef pair<int,int> P;
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<int> time(n,INT_MAX);
        unordered_map<int,vector<P>> adj;

        for(auto& meet: meetings){
            int p1 = meet[0];
            int p2 = meet[1];
            int t = meet[2];

            adj[p1].push_back({p2,t});
            adj[p2].push_back({p1,t});
        }
        queue<P> que;
        vector<int> result;

        time[0] = 0;
        time[firstPerson] = 0;
        que.push({0,0});
        que.push({firstPerson,0});


        while(!que.empty()){
            int person = que.front().first;
            int T = que.front().second;
            que.pop();

            for(auto& it: adj[person]){
                int nextperson = it.first;
                int t = it.second;

                if(T <= t && time[nextperson] > t){
                    time[nextperson] = t;
                    que.push({nextperson,t});
                }
            }
        }

        for(int i = 0;i<n;i++){
            if(time[i] != INT_MAX){
                result.push_back(i);
            }
        }

        return result;
    }
};


// Method 3 :-> DFS

class Solution {
public:
    typedef pair<int,int> P;

    void DFS(int person,int time,unordered_map<int,vector<P>>& adj,vector<int>& timeToKnow){
        for(auto& ngbr: adj[person]){
            int nextperson = ngbr.first;
            int newtime = ngbr.second;

            if(time <= newtime && timeToKnow[nextperson] > newtime){
                timeToKnow[nextperson] = newtime;
                DFS(nextperson,newtime,adj,timeToKnow);
            }
        }
    }

    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<int> time(n,INT_MAX);
        unordered_map<int,vector<P>> adj;

        for(auto& meet: meetings){
            int p1 = meet[0];
            int p2 = meet[1];
            int t = meet[2];

            adj[p1].push_back({p2,t});
            adj[p2].push_back({p1,t});
        }
        vector<int> result;

        time[0] = 0;
        time[firstPerson] = 0;


        DFS(0,0,adj,time);
        DFS(firstPerson,0,adj,time);

        for(int i = 0;i<n;i++){
            if(time[i] != INT_MAX){
                result.push_back(i);
            }
        }

        return result;
    }
};

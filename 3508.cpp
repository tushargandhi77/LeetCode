class Router {
public:
    queue<string> que;
    unordered_map<string,vector<int>> mp;
    unordered_map<int,vector<int>> Dest;
    int n;
    Router(int memoryLimit) {
        n = memoryLimit;
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        string key = to_string(source) + "_" + to_string(destination) + "_" + to_string(timestamp);

        if(mp.count(key)) return false;

        if(que.size() == n){
            forwardPacket();
        }

        que.push(key);
        mp[key] = {source,destination,timestamp};
        Dest[destination].push_back(timestamp);

        return true;

    }
    
    vector<int> forwardPacket() {
        if(que.empty()) return {};

        string key = que.front();
        que.pop();

        vector<int> vec = mp[key];
        mp.erase(key);

        int dest = vec[1];

        Dest[dest].erase(Dest[dest].begin());

        return vec;
    }
    
    int getCount(int destination, int startTime, int endTime) {
        if(Dest[destination].empty()) return 0;

        int l = lower_bound(Dest[destination].begin(),Dest[destination].end(),startTime) - begin(Dest[destination]);
        int r = upper_bound(Dest[destination].begin(),Dest[destination].end(),endTime) - begin(Dest[destination]);

        return r - l;
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */

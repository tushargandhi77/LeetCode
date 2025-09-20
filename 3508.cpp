#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
class Router {
public:
    template<class T>
    using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,    tree_order_statistics_node_update>;

// Change mp to:
unordered_map<int, ordered_set<pair<int,int>>> mp;
    queue<vector<int>> que;
    unordered_set<string> st;
    int size;
    Router(int memoryLimit) {
        size = memoryLimit;
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        string key = to_string(source) + "_" + to_string(destination) + "_" + to_string(timestamp);
        if(st.count(key)) return false;

        if(que.size() == size){
            vector<int> packet = que.front();
            string oldkey = to_string(packet[0]) + "_" + to_string(packet[1]) + "_" + to_string(packet[2]);
            mp[packet[1]].erase({packet[2],packet[0]});

            st.erase(oldkey);
            que.pop();
            que.push({source,destination,timestamp});
            st.insert(key);
        }
        else{
            que.push({source,destination,timestamp});
            st.insert(key);
        }

        mp[destination].insert({timestamp,source});

        return true;
    }
    
    vector<int> forwardPacket() {
        vector<int> packet = que.front();  
        
        if(packet.empty()) return {};

        string oldkey = to_string(packet[0]) + "_" + to_string(packet[1]) + "_" + to_string(packet[2]);

        st.erase(oldkey);
        mp[packet[1]].erase({packet[2],packet[0]});

        que.pop();
        return packet;
    }
    
    int getCount(int destination, int startTime, int endTime) {
        auto &s = mp[destination];
        if(s.empty()) return 0;

        int l = s.order_of_key({startTime, INT_MIN});
        int r = s.order_of_key({endTime+1, INT_MIN});
        return r-l;
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */

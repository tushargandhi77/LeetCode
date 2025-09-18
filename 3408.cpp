class TaskManager {
public:
    set<vector<int>> st;
    unordered_map<int,pair<int,int>> mp;
    TaskManager(vector<vector<int>>& tasks) {
        int n = tasks.size();
        for(int i = 0;i<n;i++){
            int userid = tasks[i][0];
            int taskid = tasks[i][1];
            int priority = tasks[i][2];

            st.insert({priority,taskid,userid});
            mp[taskid] = {userid,priority};
        }
    }
    
    void add(int userId, int taskId, int priority) {
        st.insert({priority,taskId,userId});
        mp[taskId] = {userId,priority};
    }
    
    void edit(int taskId, int newPriority) {
        int userid = mp[taskId].first;
        int old_priority = mp[taskId].second;

        st.erase({old_priority,taskId,userid});

        st.insert({newPriority,taskId,userid});
        mp[taskId] = {userid,newPriority};
    }
    
    void rmv(int taskId) {
        int userid = mp[taskId].first;
        int priority = mp[taskId].second;

        st.erase({priority,taskId,userid});
        mp.erase(taskId);
    }
    
    int execTop() {
        if(st.empty()) return -1;

        int priority = (*st.rbegin())[0];
        int taskid = (*st.rbegin())[1];
        int userid = (*st.rbegin())[2];

        st.erase({priority,taskid,userid});

        return userid;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */

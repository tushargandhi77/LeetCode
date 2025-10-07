class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();

        unordered_map<int,int> mp;
        set<int> st;


        vector<int> result(n,1);

        for(int i = 0;i<n;i++){
            int lake = rains[i];

            if(lake == 0){
                st.insert(i);
            }
            else{
                result[i] = -1;

                if(mp.count(lake)){
                    auto it = st.lower_bound(mp[lake]);

                    if(it == st.end()){
                        return {};
                    }

                    int day = *it;
                    result[day] = lake;
                    st.erase(it);
                }

                mp[lake] = i;
            }
        }

        return result;
    }
};

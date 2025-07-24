class Solution {
public:
    int n,m;
    vector<int> result;

    unordered_map<string,int> mp;


    void solve(int idx,int mask,vector<int>& temp,vector<int>& people_skill){
        if(idx >= people_skill.size()){
            if(mask == ((1<<n) - 1)){
                if(result.size() == 0 || temp.size() < result.size()){
                    result = temp;
                }
            }
            return;
        }

        string key = to_string(idx) + "_" + to_string(mask);

        if(mp.count(key)){
            if(mp[key] <= temp.size()) return;
        }

        if(result.size() != 0 && temp.size() >= result.size()) return;


        // skip
        solve(idx+1,mask,temp,people_skill);

        // empty people_skill
        if((mask | people_skill[idx]) == mask) return;

        // take
        temp.push_back(idx);
        solve(idx+1,mask | people_skill[idx] ,temp,people_skill);
        temp.pop_back();

        mp[key] = (temp.size() != 0) ? temp.size() : -1;
    }
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        n = req_skills.size();
        m = people.size();

        unordered_map<string,int> mp;

        for(int  i= 0;i<n;++i){
            mp[req_skills[i]] = i;
        }

        vector<int> people_skill;
        for(auto& v: people){
            int skill = 0;
            for(string& s: v){
                skill = skill | (1 << mp[s]);
            }
            people_skill.push_back(skill);
        }

        vector<int> temp;
        solve(0,0,temp,people_skill);

        return result;
    }
};

class Solution {
public:
    struct comp{
        bool operator()(auto& P1,auto& P2){
            if(P1.first == P2.first){
                return P1.second < P2.second;
            }
            return P1.first > P2.first;
        }
    };
    string clearStars(string s) {
        string result = "";

        priority_queue<pair<char,int>,vector<pair<char,int>>,comp> pq;

        for(int i = 0;i<s.length();i++){
            if(s[i] != '*'){
                pq.push({s[i],i});
            }
            else{
                int idx = pq.top().second;
                pq.pop();
                s[idx] = '*';
            }
        }

        for(int i = 0;i<s.length();i++){
            if(s[i] != '*'){
                result += s[i];
            }
        }

        return result;
    }
};

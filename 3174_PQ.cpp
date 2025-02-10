class Solution {
public:
    bool isdigit(char ch){
        if(ch == '1' || ch == '2' || ch == '3' || ch == '4' || ch == '5' || ch == '6' || ch == '7' || ch == '8' || ch == '9' || ch == '0'){
            return true;
        }
        return false;
    }
    string clearDigits(string s) {
        string result = "";

        int n = s.length();

        priority_queue<int,vector<int>> pq;
        


        for(int i = 0;i<n;i++){
            if(isdigit(s[i])){
                s[i] = '.';
                if(!pq.empty()){
                    int idx = pq.top();
                    pq.pop();
                    s[idx] = '.';
                }
            }
            else{
                pq.push(i);
            }
        }

        for(auto ch : s){
            if(ch != '.'){
                result += ch;
            }
        }
        return result;
    }
};

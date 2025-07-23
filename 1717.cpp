class Solution {
public:

    int solve(string& s,char first,char second,int x){
        string newstr = "";
        int answer = 0;

        for(char& ch: s){
            if(!newstr.empty() && newstr.back() == first && ch == second){
                answer+= x;
                newstr.pop_back();
            }
            else{
                newstr.push_back(ch);
            }
        }

        s = newstr;
        return answer;
    }
    int maximumGain(string s, int x, int y) {
        int answer = 0;


        if(x > y){
            answer = solve(s,'a','b',x);
            answer += solve(s,'b','a',y);
        }
        else{
            answer = solve(s,'b','a',y);
            answer += solve(s,'a','b',x);
        }

        return answer;
    }
};

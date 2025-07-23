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

class Solution {
public:
    string removeSubstr(string& s,string& matchStr){
        int i =0;
        for(int j = 0;j<s.length();j++){
            s[i] = s[j];
            i++;
            if(i >= 2 &&s[i-2] == matchStr[0] && s[i-1] == matchStr[1]){
                i -= 2;
            }
        }

        s.erase(begin(s)+i,end(s));

        return s;
    }
    int maximumGain(string s, int x, int y) {
        int n = s.length();
        int score = 0;

        string maxStr = (x > y) ? "ab" : "ba";
        string minStr = (maxStr == "ab") ? "ba" : "ab";

        // first pass
        string temp_first = removeSubstr(s,maxStr);
        int L = temp_first.length();

        int charRemoved = (n-L);
        score += (charRemoved/2) * max(x,y);

        string temp_second = removeSubstr(temp_first,minStr);
        charRemoved = L - temp_second.length();

        score += (charRemoved/2) * min(x,y);
        
        return score;
    }
};

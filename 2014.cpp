// Backtracking 1 

class Solution {
public:
    string result = "";
    
    bool isSubsequence(string& s,string& curr,int k){
        int n = s.length();
        int m = curr.length();
        int i = 0;
        int j = 0;

        while(i < n && j < m*k){
            if(s[i] == curr[j%m]) j++;
            i++;
        }

        return j == m*k;
    }

    void Backtracking(string& s,string& curr,vector<bool>& canUse,vector<int>& requiredFreq,int k,int maxLen){
        if(curr.length() > maxLen){
            return;
        }

        if((curr.length() > result.length() || (curr.length() == result.length() && curr > result)) && isSubsequence(s,curr,k)){
            result = curr;
        }

        for(int i = 0;i<26;i++){
            if(canUse[i] == false || requiredFreq[i] == 0) continue;
            
            // Do
            char ch = i + 'a';
            curr.push_back(ch);
            requiredFreq[i]--;

            // Explore
            Backtracking(s,curr,canUse,requiredFreq,k,maxLen);

            // Undo
            curr.pop_back();
            requiredFreq[i]++;

        }
    }
    string longestSubsequenceRepeatedK(string s, int k) {
        int n = s.length();

        vector<int> freq(26,0);

        for(char& c: s){
            freq[c-'a']++;
        }

        vector<bool> canUse(26,false);
        vector<int> requiredFreq(26,0);

        for(int i = 0;i<26;i++){
            if(freq[i] >= k){
                canUse[i] = true;
                requiredFreq[i] = freq[i] / k;
            }
        }

        int maxLen = n/k;
        string curr;

        Backtracking(s,curr,canUse,requiredFreq,k,maxLen);

        return result;
    }
};

// Backtracking 2

class Solution {
public:
    string result = "";
    
    bool isSubsequence(string& s,string& curr,int k){
        int n = s.length();
        int m = curr.length();
        int i = 0;
        int j = 0;

        while(i < n && j < m*k){
            if(s[i] == curr[j%m]) j++;
            i++;
        }

        return j == m*k;
    }

    bool Backtracking(string& s,string& curr,vector<bool>& canUse,vector<int>& requiredFreq,int k,int maxLen){
        if(curr.length() == maxLen){
            if(isSubsequence(s,curr,k)){
                result = curr;
                return true;
            }
            return false;
        }

        for(int i = 25;i>=0;i--){
            if(canUse[i] == false || requiredFreq[i] == 0) continue;
            
            // Do
            char ch = i + 'a';
            curr.push_back(ch);
            requiredFreq[i]--;

            // Explore
            if(Backtracking(s,curr,canUse,requiredFreq,k,maxLen)==true){
                return true;
            }

            // Undo
            curr.pop_back();
            requiredFreq[i]++;

        }

        return false;
    }
    string longestSubsequenceRepeatedK(string s, int k) {
        int n = s.length();

        vector<int> freq(26,0);

        for(char& c: s){
            freq[c-'a']++;
        }

        vector<bool> canUse(26,false);
        vector<int> requiredFreq(26,0);

        for(int i = 0;i<26;i++){
            if(freq[i] >= k){
                canUse[i] = true;
                requiredFreq[i] = freq[i] / k;
            }
        }

        int maxLen = n/k;
        string curr;

        for(int len = maxLen;len>=0;len--){
            vector<int> tempRequiredFreq = requiredFreq;
            if(Backtracking(s,curr,canUse,tempRequiredFreq,k,len)==true){
                return result;
            }
        }

        return result;
    }
};

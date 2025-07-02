// Recursion 

class Solution {
public:
    int M = 1e9 + 7;

    int solve(int i,int count,vector<int>& freq,int k){
        if(i >= freq.size()){
            if(count < k) return 1;
            
            return 0;
        }

        long long result = 0;
        for(int take = 1;take<=freq[i];take++){
            if(count + take < k){
                result = (result  + solve(i+1,count+take,freq,k)) % M;
            }
            else{
                break;
            }
        }

        return result;
    }
    int possibleStringCount(string word, int k) {
        if(k > word.length()) return 0;

        vector<int> freq;
        int count = 1;

        for(int i = 1;i<word.length();i++){
            if(word[i] == word[i-1]){
                count++;
            }
            else{
                freq.push_back(count);
                count = 1;
            }
        }
        freq.push_back(count);

        int P = 1;

        for(int& f: freq){
            P = (P * f) % M;
        }

        if(freq.size() >= k){
            return P;
        }

        long long invalidCount = solve(0,0,freq,k);

        return P - invalidCount;
    }
};


// MEMO
class Solution {
public:
    int M = 1e9 + 7;
    vector<vector<int>> t;
    int solve(int i,int count,vector<int>& freq,int k){
        if(i >= freq.size()){
            if(count < k) return 1;
            
            return 0;
        }

        if(t[i][count] != -1) return t[i][count];

        long long result = 0;
        for(int take = 1;take<=freq[i];take++){
            if(count + take < k){
                result = (result  + solve(i+1,count+take,freq,k)) % M;
            }
            else{
                break;
            }
        }

        return t[i][count] = result;
    }
    int possibleStringCount(string word, int k) {
        if(k > word.length()) return 0;

        vector<int> freq;
        int count = 1;

        for(int i = 1;i<word.length();i++){
            if(word[i] == word[i-1]){
                count++;
            }
            else{
                freq.push_back(count);
                count = 1;
            }
        }
        freq.push_back(count);

        long long P = 1;

        for(int& f: freq){
            P = (P * f) % M;
        }

        if(freq.size() >= k){
            return P;
        }
        int n = freq.size();
        t.assign(n+1,vector<int>(k+1,-1));

        long long invalidCount = solve(0,0,freq,k);

        return (P - invalidCount + M ) % M;
    }
};

// Bottom Up

class Solution {
public:
    int M = 1e9 + 7;
    
    int possibleStringCount(string word, int k) {
        if(k > word.length()) return 0;

        vector<int> freq;
        int count = 1;

        for(int i = 1;i<word.length();i++){
            if(word[i] == word[i-1]){
                count++;
            }
            else{
                freq.push_back(count);
                count = 1;
            }
        }
        freq.push_back(count);

        long long P = 1;

        for(int& f: freq){
            P = (P * f) % M;
        }

        if(freq.size() >= k){
            return P;
        }
        int n = freq.size();

        vector<vector<int>> t(n+1,vector<int>(k+1,0));

        for(int count = k-1;count>=0;count--){
            t[n][count] = 1;
        }

        for(int i = n-1;i>=0;i--){
            for(int count = k-1;count>=0;count--){
                
                long long result = 0;
                for(int take = 1;take<=freq[i];take++){
                    if(count+take < k){
                        result  = (result + t[i+1][count+take])%M;
                    }
                }

                t[i][count] = result;

            }
        }

        long long invalidCount = t[0][0];

        return (P - invalidCount + M ) % M;
    }
};

// Optimal BU

class Solution {
public:
    int M = 1e9 + 7;
    
    int possibleStringCount(string word, int k) {
        if(k > word.length()) return 0;

        vector<int> freq;
        int count = 1;

        for(int i = 1;i<word.length();i++){
            if(word[i] == word[i-1]){
                count++;
            }
            else{
                freq.push_back(count);
                count = 1;
            }
        }
        freq.push_back(count);

        long long P = 1;

        for(int& f: freq){
            P = (P * f) % M;
        }

        if(freq.size() >= k){
            return P;
        }
        int n = freq.size();

        vector<vector<int>> t(n+1,vector<int>(k+1,0));

        for(int count = k-1;count>=0;count--){
            t[n][count] = 1;
        }

        for(int i = n-1;i>=0;i--){

            vector<int> prefix(k+1,0);

            for(int h = 1;h<=k;h++){
                prefix[h] = (prefix[h-1] + t[i+1][h-1]) % M;
            }
            for(int count = k-1;count>=0;count--){
                
                int l = count + 1;
                int r = count + freq[i];

                if(r+1 > k){
                    r = k-1;
                }

                if(l <= r){
                    t[i][count] = (prefix[r+1] - prefix[l] + M) % M;
                }

            }
        }

        long long invalidCount = t[0][0];

        return (P - invalidCount + M ) % M;
    }
};

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>,vector<pair<int,char>>> pq;
        string result = "";
        if(a > 0) pq.push({a,'a'});
        if(b > 0) pq.push({b,'b'});
        if(c > 0) pq.push({c,'c'});

        while(!pq.empty()){
            int currCount = pq.top().first;
            char currChar = pq.top().second;
            pq.pop();

            if(result.length() >= 2 && result[result.length()-1] == currChar && result[result.length() - 2] == currChar){
                if(pq.empty()) break;

                int nextCount = pq.top().first;
                char nextChar = pq.top().second;
                pq.pop();
                result.push_back(nextChar);
                nextCount--;
                if(nextCount > 0){
                    pq.push({nextCount,nextChar});
                }
            }
            else{
                currCount--;
                result.push_back(currChar);
            }
            if(currCount > 0){
                pq.push({currCount,currChar});
            }
        }
        return result;
    }
};

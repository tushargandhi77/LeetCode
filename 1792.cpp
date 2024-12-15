class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double,int>> pq;

        int n = classes.size();

        for(int i = 0;i<n;i++){
            double old_pr = (double)(classes[i][0])/(classes[i][1]);
            double new_pr = (double)(classes[i][0]+1)/(classes[i][1]+1);
            double delta = new_pr - old_pr;
            pq.push({delta,i});
        }

        while(extraStudents--){
            auto curr = pq.top();
            pq.pop();

            int idx = curr.second;

            classes[idx][0]++;
            classes[idx][1]++;

            double old_pr = (double)(classes[idx][0])/(classes[idx][1]);
            double new_pr = (double)(classes[idx][0]+1)/(classes[idx][1]+1);
            double delta = new_pr - old_pr;

            pq.push({delta,idx});
        }

        double result = 0.0;

        for(int i = 0;i<n;i++){
            result += (double)classes[i][0]/classes[i][1];
        }
        return result/n;
    }
};

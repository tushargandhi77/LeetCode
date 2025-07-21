class Solution {
public:
    int t[101][501];
    const int MOD = 1e9+7;

    int solve(int start,int fuel,int finish,vector<int>& locations){
        if(fuel < 0) return 0;

        if(t[start][fuel+201] != -1) return t[start][fuel+201];

        int answer = 0;

        if(start == finish){
            answer = 1;
        }

        for(int i = 0;i<locations.size();i++){
            if(start == i) continue;
            
            int fuelused = abs(locations[i]-locations[start]);
            answer = (answer + solve(i,fuel-fuelused,finish,locations)%MOD)%MOD;
        }

        return t[start][fuel+201] = answer%MOD;
    }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        memset(t,-1,sizeof(t));
        return solve(start,fuel,finish,locations);
    }
};

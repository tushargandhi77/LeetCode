class Solution {
public:
    vector<vector<int>> soups{{100,0},{75,25},{50,50},{25,75}};
    double solve(int A,int B,vector<vector<double>>& t){
        if(A <= 0 && B <= 0) return 0.5;

        if(A <= 0) return 1.0;

        if(B <= 0) return 0.0;

        if(t[A][B] != -1) return t[A][B];

        double result = 0.0;
        for(auto soup: soups){
            int A_soup = soup[0];
            int B_soup = soup[1];

            result += 0.25*solve(A-A_soup,B-B_soup,t);
        }
        return t[A][B] = result;
    }
    double soupServings(int n) {
        if(n >= 5000) return 1;

        vector<vector<double>> t(n+1,vector<double>(n+1,-1));
        return solve(n,n,t);
    }
};

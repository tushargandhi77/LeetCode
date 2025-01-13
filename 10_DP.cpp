class Solution {
public:
    int t[21][21];
    bool solve(int i,int j,string s,string p){
        if(p.length() == j){
            return s.length() == i;
        }

        if(t[i][j] != -1) return t[i][j];

        bool first_order_matched = false;

        if(i < s.length() && (p[j] == s[i] || p[j] == '.')){
            first_order_matched = true;
        }
        if(p[j+1] == '*'){
            bool not_take = solve(i,j+2,s,p);
            bool take = ( first_order_matched && solve(i+1,j,s,p));
            return t[i][j] = not_take || take;
        }
        else{
            return t[i][j] = (first_order_matched && solve(i+1,j+1,s,p));
        }
    }
    bool isMatch(string s, string p) {
        memset(t,-1,sizeof(t));
        return solve(0,0,s,p);
    }
};

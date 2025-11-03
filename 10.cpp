class Solution {
public:
    bool solve(string s,string p){
        if(p.length() == 0){
            return s.length() == 0;
        }
        bool first_order_matched = false;
        if(s.length() > 0 && (p[0] == s[0] || p[0] == '.')){
            first_order_matched = true;
        }
        if(p[1] == '*'){
            bool not_take = solve(s,p.substr(2));
            bool take = ( first_order_matched && solve(s.substr(1),p));
            return not_take || take;
        }
        else{
            return (first_order_matched && solve(s.substr(1),p.substr(1)));
        }
    }
    bool isMatch(string s, string p) {
        return solve(s,p);
        
    }
};




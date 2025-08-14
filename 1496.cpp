class Solution {
public:
    bool isPathCrossing(string path) {
        int x = 0;
        int y = 0;

        set<pair<int,int>> st;
        st.insert({x,y});

        for(char ch: path){
            if(ch == 'E'){
                x++;
            }
            if(ch == 'W'){
                x--;
            }
            if(ch == 'N'){
                y++;
            }
            if(ch == 'S'){
                y--;
            }


            if(st.count({x,y})) return true;

            st.insert({x,y});
        }

        return false;
    }
};

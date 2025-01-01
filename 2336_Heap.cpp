class SmallestInfiniteSet {
public:
    int currsmallest;
    unordered_set<int> st;
    priority_queue<int,vector<int>,greater<int>> pq;
    SmallestInfiniteSet() {
        currsmallest = 1;
    }
    
    int popSmallest() {
        int result = 0;

        if(!pq.empty()){
            result = pq.top();
            pq.pop();
            st.erase(result);
        }
        else{
            result = currsmallest;
            currsmallest += 1;
        }

        return result;
    }
    
    void addBack(int num) {
        if(num >= currsmallest || st.find(num) != st.end()){
            return;
        }

        st.insert(num);
        pq.push(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */

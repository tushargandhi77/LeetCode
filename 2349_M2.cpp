class NumberContainers {
public:
    unordered_map<int,int> idxTonum;
    unordered_map<int,priority_queue<int,vector<int>,greater<int>>> numToidxs;

    NumberContainers() {
        idxTonum.clear();
        numToidxs.clear();    
    }
    
    void change(int index, int number) {

        idxTonum[index] = number;
        numToidxs[number].push(index);

    }
    
    int find(int number) {
        if(numToidxs.count(number)){
            while(!numToidxs[number].empty()){
                int idx = numToidxs[number].top();
                if(idxTonum[idx] == number){
                    return idx;
                }
                else{
                    numToidxs[number].pop();
                }
            }
        }
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */

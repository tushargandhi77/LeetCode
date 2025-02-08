class NumberContainers {
public:
    unordered_map<int,int> idxTonum;
    unordered_map<int,set<int>> numToidxs;

    NumberContainers() {
        idxTonum.clear();
        numToidxs.clear();    
    }
    
    void change(int index, int number) {
        if(idxTonum.count(index)){
            int prev = idxTonum[index];
            numToidxs[prev].erase(index);

            if(numToidxs[prev].empty()){
                numToidxs.erase(prev);
            }
        }

        idxTonum[index] = number;
        numToidxs[number].insert(index);
    }
    
    int find(int number) {
        if(numToidxs.count(number)){
            return *numToidxs[number].begin();
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

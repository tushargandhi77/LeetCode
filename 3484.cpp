class Spreadsheet {
public:
    vector<vector<int>> sheet;
    bool isNumber(string s){
        if(s.empty()) return false;
        for(char c: s){
            if(!isdigit(c)) return false;
        }
        return true;
    }
    Spreadsheet(int rows) {
        sheet.resize(rows+1,vector<int>(26,0));
    }
    
    void setCell(string cell, int value) {
        int col = cell[0] - 'A';
        int row = stoi(cell.substr(1));
        sheet[row][col] = value;
    }
    
    void resetCell(string cell) {
        int col = cell[0] - 'A';
        int row = stoi(cell.substr(1));
        sheet[row][col] = 0;
    }
    
    int getValue(string formula) {
        formula = formula.substr(1);
        char delimeter = '+';

        stringstream ss(formula);
        string word;
        int result = 0;
        while(getline(ss,word,delimeter)){
            if(isNumber(word)){
                result+=stoi(word);
            }
            else{
                int col = word[0] - 'A';
                int row = stoi(word.substr(1));
                result += sheet[row][col];
            }

        }
        return result;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */

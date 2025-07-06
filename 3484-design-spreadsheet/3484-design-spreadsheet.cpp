class Spreadsheet {
public:
    vector<vector<int>> grid;
    Spreadsheet(int rows) {
        grid.resize(rows+1,vector<int>(26));
    }
    
    pair<int,int> getRowCol(string cell) {
        // Alphabet  X(multiple digits)
        int col = cell[0]-'A';
        int row = getValFromStr(cell.substr(1));
        return {row,col};
    }

    int getValFromStr(string str) {
        int val = 0;
        int index = 0;
        while(index<str.length()) {
            val = val*10+str[index]-'0'; 
            index++;
        }
        return val;
    }

    void setCell(string cell, int value) {
        auto [row,col] = getRowCol(cell);
        grid[row][col]=value;
        return;
    }
    
    void resetCell(string cell) {
        auto [row,col] = getRowCol(cell);
        grid[row][col]=0;
        return; 
    }


    
    int getValue(string formula) {
        // cell or value divided delimiter +
        int index = formula.find('+');
        int val1 = 0,val2 = 0;
        if(formula[1]>='A' && formula[1]<='Z') {
            auto [row,col] = getRowCol(formula.substr(1,index-1));
            val1 = grid[row][col];
        } else {
            val1 = getValFromStr(formula.substr(1,index-1));
        }

        if(formula[index+1]>='A' && formula[index+1]<='Z') {
            auto [row,col] = getRowCol(formula.substr(index+1));
            val2 = grid[row][col];
        } else {
            val2 = getValFromStr(formula.substr(index+1));
        }
        return val1+val2;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */
class Solution {
public:
    vector<string> ans;
    
    vector<string> addOperators(string num, int target) {
        // Start backtracking with empty expression, start at index 0, 0 as current value, and 0 as last operand
        solve(num, target, "", 0, 0, 0);
        return ans;
    }

    // Backtracking function
    void solve(string& num, int target, string expr, int pos, long currVal, long lastOperand) {
        // If we have reached the end of the string
        if (pos == num.size()) {
            // Check if the current expression evaluates to the target
            if (currVal == target) {
                ans.push_back(expr);  // Add expression to results
            }
            return;
        }
        
        // Try every possible split of the number string
        for (int i = pos; i < num.size(); ++i) {
            // Avoid numbers with leading zeroes
            if (i > pos && num[pos] == '0') break;
            
            // Extract the substring and convert it to a number
            string part = num.substr(pos, i - pos + 1);
            long currNum = stol(part);
            
            // If we're at the start, just take the current number without adding an operator
            if (pos == 0) {
                solve(num, target, expr + part, i + 1, currNum, currNum);
            } else {
                // Try addition
                solve(num, target, expr + "+" + part, i + 1, currVal + currNum, currNum);
                
                // Try subtraction
                solve(num, target, expr + "-" + part, i + 1, currVal - currNum, -currNum);
                
                // Try multiplication
                solve(num, target, expr + "*" + part, i + 1, currVal - lastOperand + lastOperand * currNum, lastOperand * currNum);
            }
        }
    }
};

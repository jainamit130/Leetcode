class Solution {
public:
    unordered_set<char> st = {'*', '+', '-'};
    vector<int> diffWaysToCompute(string expression) {
        return solve(expression, 0, expression.length() - 1);
    }

    vector<int> solve(string expression, int start, int end) {
        if (start > end) {
            return {};
        }
        vector<int> ans;
        bool flag=0;
        int num=0;
        for (int i = start; i <= end; i++) {
            if (st.find(expression[i]) != st.end()) {
                flag=1;
                vector<int> left = solve(expression, start, i - 1);
                vector<int> right = solve(expression, i + 1, end);
                if (expression[i] == '*') {
                    for(int j=0;j<left.size();j++){
                        for(int k=0;k<right.size();k++){
                            ans.push_back(left[j]*right[k]);
                        }
                    }
                } else if (expression[i] == '-') {
                    for(int j=0;j<left.size();j++){
                        for(int k=0;k<right.size();k++){
                            ans.push_back(left[j]-right[k]);
                        }
                    }
                } else if (expression[i] == '+') {
                    for(int j=0;j<left.size();j++){
                        for(int k=0;k<right.size();k++){
                            ans.push_back(left[j]+right[k]);
                        }
                    }
                }
            } else {
                num = num * 10 + (expression[i] - 48);
            }
        }
        if(flag==0){
            return {num};
        }
        return ans;
    }
};
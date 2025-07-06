class Solution {
public:
    int minOperations(std::vector<std::string>& logs) {
        int res = 0;

        for (const string& log : logs) {
            if (log == "../") {
                if (res > 0) {
                    res--;
                }
            } else if (log != "./") {
                res++;
            }
        }

        return res;
    }
};
class Solution {
public:
    string makeLargestSpecial(string s) {
        int count = 0, i = 0;
        vector<string> res;
        
        for (int j = 0; j < s.length(); j++) {
            count += (s[j] == '1') ? 1 : -1;
            
            if (count == 0) {
                res.push_back('1' + makeLargestSpecial(s.substr(i + 1, j - i - 1)) + '0');
                i = j + 1;
            }
        }
        
        sort(res.begin(), res.end(), greater<string>());
        
        string result;
        for (const string& str : res) {
            result += str;
        }
        return result;
    }
};

/*

0   1   2   3   4   5   6   7
1   1   0   1   1   0   0   0

7   2       6   5
    6


1   1   0   1   1   0   0   0   

1   2   2   3   4   4   4   4
4   3   2   2   1   0   0   0


1   1   1   0   0   0   
1   1   0   
1   0 
0   
1   1   1   0   0   
1   0   
0

1111000
10
0
11100
10
0
10


*/
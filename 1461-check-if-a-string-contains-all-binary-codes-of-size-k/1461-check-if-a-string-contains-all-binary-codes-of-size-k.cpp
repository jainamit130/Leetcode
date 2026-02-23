class Solution {
public:
    bool hasAllCodes(string& s, int t) {
        int n = s.length();
        int totalNums = pow(2, t);
        unordered_set<int> st;
        for (int i = 0; i < totalNums; i++) st.insert(i);
        int val = 0;
        int k = 0, l = 0;
        int flag = 1;
        int length = t;
        while (l < s.length()) {
            if ((l - k + 1) < t) {
                if (s[l] - '0') val += pow(2, length - 1);
                length--;
                l++;
            } else {
                if (s[l] - '0') val += 1;
                st.erase(val);
                if (s[k] - '0') val -= pow(2, t - 1);
                val *= 2;
                l++; k++;
            }
        }
        return st.size()==0;
    }
};

/*


1   1   0   1   0   1   0   0   1   1   0   1   0   0   1
k
            l

6-4+1



1 - 0,1
2 - 2,3
3 - 4,5,6,7
4 - 8,9,10,11,12,13,14,15
5 - 16,17,18,19,20


*/
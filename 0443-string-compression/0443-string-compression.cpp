class Solution {
public:
    int compress(vector<char>& chars) {
        int k = 0;
        int i = 0;
        int count;
        while (i < chars.size()) {
            count = 1;
            char c = chars[i];
            int j = i + 1;
            while (j < chars.size() && chars[j] == c) {
                count++;
                j++;
            }
            if (count > 1 && k < chars.size()) {
                chars[k] = c;
                k++;
                string strCount = to_string(count);
                for (char ch : strCount) {
                    chars[k] = ch;
                    k++;
                }
            } else {
                chars[k] = c;
                k++;
            }
            i = j;
        }
        return k;
    }
};
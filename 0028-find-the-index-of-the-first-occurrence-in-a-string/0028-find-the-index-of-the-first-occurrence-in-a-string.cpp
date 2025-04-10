class Solution {
public:
    int strStr(string text, string pattern) {
        vector<int> zArr = computeZ(pattern + "$" + text);
        int len = pattern.length();
        vector<int> ans;
        for (int i = len + 1; i < zArr.size(); i++)
        {
            if (zArr[i] == pattern.length())
            {
                return i - len - 1;
            }
        }
        return -1;
    }

    vector<int> computeZ(const string &s)
    {
        int n = s.length();
        vector<int> z(n);
        int index = 1;
        while (index < n)
        {
            int left = index;
            int right = left;
            while (right < s.length() && s[right - left] == s[right])
                right++;
            z[index] = right - left;
            index++;
            while (index < right && index + z[index - left] < right)
            {
                z[index] = z[index - left];
                index++;
            }
        }

        return z;
    }
};
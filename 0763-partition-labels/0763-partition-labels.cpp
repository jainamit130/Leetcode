class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.length();
        vector<int> lastOccurences(26,-1);
        for(int i=0;i<n;i++) {
            lastOccurences[s[i]-'a']=i;
        }

        vector<int> ans;
        int index = 0;
        while(index<n) {
            int subAns = 0;
            int lastIndex = lastOccurences[s[index]-'a'];
            int startIndex = index;
            while(startIndex<n && startIndex<=lastIndex) {
                lastIndex = max(lastIndex,lastOccurences[s[startIndex]-'a']);
                startIndex++;
            }
            ans.push_back(startIndex-index);
            index=startIndex;
        }
        return ans;
    }
};

/*


a   b   a   b   c   b   a   c   a   d   e   f   e   g   d   e   h   i   j   h   k   l   i   j
0   1   2   3   4   5   6   7   8   9   10  11  12  13  14  15  16  17  18  19  20  21  22  23
8   5   8   5   7   5   8   7   8   14  15  11  15  13  14  15  19  22  23  19  20  21  22  23


*/
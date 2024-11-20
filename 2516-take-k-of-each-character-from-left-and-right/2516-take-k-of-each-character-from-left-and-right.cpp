class Solution {
public:
    int takeCharacters(string s, int k) {
        if(k==0){
            return 0;
        }
        vector<vector<int>> prefix;
        int ans = INT_MAX;
        prefix.push_back({0, 0, 0});
        for (int i = 0; i < s.length(); i++) {
            prefix.push_back(prefix.back());
            prefix.back()[s[i] - 'a']++;
            int flag = 1;
            for(int t=0;t<3;t++) {
                if(prefix.back()[t]<k) {
                    flag=0;
                }
            }
            if(flag){
                ans=min(ans,i+1);
            }
        }

        if (INT_MAX == ans) {
            return -1;
        }

        vector<int> suffix(3);
        for (int j = s.length() - 1; j > 0; j--) {
            suffix[s[j] - 'a']++;
            int start = 0;
            int end = j - 1;
            while (start <= end) {
                int mid = (start + end) / 2;
                int flag = 1;
                int flag1 = 1;
                for (int t = 0; t < 3; t++) {
                    if (prefix[mid + 1][t] + suffix[t] < k && k > 0) {
                        flag = 0;
                    }
                    if(suffix[t]<k){
                        flag1=0;
                    }
                }
                if(flag1) {
                    int subAns = s.length() - j;
                    ans = min(ans,subAns);
                }
                if (flag) {
                    int subAns = s.length() - j + mid + 1;
                    ans = min(ans, subAns);
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            }
        }
        return ans;
    }
};

/*

        i
                            j
a   a   b   a   a   a   a   c   a   a   b   c




*/
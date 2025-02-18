class Solution {
public:
    int shortestMatchingSubstring(string s, string p) {
        string group1="";
        string group2="";
        string group3="";
        int count = 0;
        for(int i=0;i<p.length();i++) {
            if(p[i]=='*') {
                count++;
            } else {
                if(count==0) {
                    group1+=p[i];
                } else if(count==1){
                    group2+=p[i];
                } else {
                    group3+=p[i];
                }
            }
        }

        vector<int> matchIndexes1 = getMatchingIndexes(group1, s);
        vector<int> matchIndexes2 = getMatchingIndexes(group2, s);
        vector<int> matchIndexes3 = getMatchingIndexes(group3, s);

        int res = INT_MAX;
        int i=0,j=0,k=0;

        while((i+group2.length()+group3.length())<s.length()) {
            while(i<s.length() && matchIndexes1[i]!=group1.length()) i++;
            if(i>=s.length()) break;

            while(j<s.length() && (j<i+group2.length() || matchIndexes2[j]!=group2.length())) j++;
            if(j>=s.length()) break;

            while(k<s.length() && (k<j+group3.length() || matchIndexes3[k]!=group3.length())) k++;
            if(k>=s.length()) break;

            res = min(res,k-i+(int)group1.size());
            i++;
        }


        return res == INT_MAX ? -1 : res;
    } 

    vector<int> getMatchingIndexes(string pattern,string s) {
        vector<int> matchIndexes(s.length(),0);
        if(pattern.length()==0) return matchIndexes;
        vector<int> lps = getLPS(pattern);
        int i=0,j=0;
        while(i<s.length()) {
            if(s[i]==pattern[j]) {
                i++;
                j++;
                if(j==pattern.length()) {
                    matchIndexes[i-1]=pattern.length();
                    j = lps[j-1];
                }
            } else {
                if(j!=0) j = lps[j-1];
                else i++;
            }
        }
        return matchIndexes;
    }

    vector<int> getLPS(string pattern) {
        vector<int> lps(pattern.length());
        int i=1;
        int length=0;
        while(i<pattern.length()) {
            if(pattern[length]==pattern[i]) {
                length++;
                lps[i]=length;
                i++;
            } else {
                if(length!=0) length = lps[length-1];
                else i++;
            }
        }
        return lps;
    }
};


/*

    

*/
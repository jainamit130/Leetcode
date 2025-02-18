class Solution {
public:
    int shortestMatchingSubstring(string s, string p) {
        string group1 = "",group2="",group3="";
        int count = 0;
        for(auto ch:p) {
            if(ch=='*') count++;
            else {
                if(count==0) group1+=ch;
                if(count==1) group2+=ch;
                if(count==2) group3+=ch;
            }
        }

        vector<int> matchIndexes1 = getMatchingIndexes(group1,s);
        vector<int> matchIndexes2 = getMatchingIndexes(group2,s);
        vector<int> matchIndexes3 = getMatchingIndexes(group3,s);

        int i=0,j=0,k=0;
        int res = INT_MAX;

        int n = s.length();
        int seg1 = group1.length();
        int seg2 = group2.length();
        int seg3 = group3.length();
        while(i+seg2+seg3<s.length()) {
            while(i<n && matchIndexes1[i]!=seg1) i++;
            if(i>=n) break;

            j = i+seg2;
            while(j<n && matchIndexes2[j]!=seg2) j++;
            if(j>=n) break;

            k = j+seg3;
            while(k<n && matchIndexes3[k]!=seg3) k++;
            if(k>=n) break;

            res = min(res,k-i+seg1);
            i++;
        }

        return res==INT_MAX?-1:res;
    }

    vector<int> getMatchingIndexes(string pattern,string s) {
        vector<int> matchIndexes(s.length());
        if(pattern.length()==0) return matchIndexes;
        vector<int> lps = getLPS(pattern); 
        int i=0,j=0;
        while(i<s.length()) {
            if(s[i]==pattern[j]) {
                j++;
                if(pattern.length()==j) {
                    matchIndexes[i]=pattern.length();
                    j = lps[j-1];
                }
                i++;
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
        int length = 0;
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
length = 0
                i
a   a   a   c   a   a   a
0   1   2   0



LPS[i] => from 0 to i whats the longest prefix which is equal to the suffix 

LPS[0]=> 0 to 0 of pattern has 0 lps

a   b   a   a   c   b   a   e   c   e   b   c   e


0   0   2   0   0   0   2   0   0   0   0   0   0
        i
0   0   0   0   1   0   0   0   1   0   0   0   0
                j
0   0   0   0   0   0   0   0   0   2   0   0   2
                                    k

0011222  
ba*c*ce

ba
c
ce

Steps:

1. Get the groups
2. for every group/pattern get the lps 
3. now start a 3 pointer appraoch

*/
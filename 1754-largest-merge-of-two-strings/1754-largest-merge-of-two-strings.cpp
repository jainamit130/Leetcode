class Solution {
public:
    string largestMerge(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        string ans = "";
        int i=0,j=0;
        while(i<m || j<n) {
            if(i<m) {
                if(j<n) {
                    if(word1[i]==word2[j]) {
                        if(word1.substr(i)>word2.substr(j)) {
                            ans+=word1[i];
                            i++;
                        } else {
                            ans+=word2[j];
                            j++;
                        }
                    } else if(word1[i]<word2[j]) {
                        ans+=word2[j];
                        j++;
                    } else {
                        ans+=word1[i];
                        i++;
                    }
                } else {
                    ans+=word1[i];
                    i++;
                } 
            } else {
                ans+=word2[j];
                j++; 
            }
        }
        return ans;
    }
};


/*

a   b   c   a   b   c
    i

a   b   d   c   a   b   a
j

a   b


given word1 and word2


Ex:

h   c   b   e   g   s   a   n

g   d   y   c   v   n

merge= hgdycvncbegsan



*/
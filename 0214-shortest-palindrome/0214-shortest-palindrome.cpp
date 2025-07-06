class Solution {
public:
    void lps(string & pattern , int & n , vector<int>&lpss)
    {
        int i = 1;
        int j = 0;
        while(i<n)
        {
            if(pattern[i]==pattern[j])
            {
                j++;
                lpss[i]=j;
                i++;
            }
            else 
            {
                if(j==0)
                {
                    lpss[i]=0;
                    i++;
                }
                else
                {
                    j = lpss[j-1];
                }
            }
        }
    }
    string shortestPalindrome(string s) 
    {
        string t=s;
        reverse(s.begin(),s.end());
        t+="#";
        t+=s;
        reverse(s.begin(),s.end());
        int n = t.size();
        vector<int> lpss(n);
        
        lps(t,n,lpss);

        int matchedSubStr = lpss[n-1];

        string tobeAdded = s.substr(matchedSubStr);
        reverse(tobeAdded.begin(),tobeAdded.end());
        return tobeAdded + s;    
    }
};
/*

a   a   c   e   c   a   a   a
i

a   a   a   c   e   c   a   a
j


a   b   c   d
i

d   c   b   a
            j


*/
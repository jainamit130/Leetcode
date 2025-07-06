class Solution {
public:
    unordered_map<int,vector<char>> mp;
    vector<string> ans;
    vector<string> letterCombinations(string digits) {
        if(digits.length()==0) return {};
        int count = 3;
        int currCh = 'a'; 
        for(int i=2;i<=9;i++) {
            if(i==7 || i==9) count = 4;
            else count = 3;
            while(count) {
                mp[i].push_back(currCh);
                currCh++;
                count--;
            }
        }

        solve(digits,0,"");
        return ans;
    }

    void solve(string digits,int index,string curr) {
        if(index>=digits.length()) {
            ans.push_back(curr);
            return;
        }

        for(int i=0;i<mp[digits[index]-'0'].size();i++) {
            solve(digits,index+1,curr+mp[digits[index]-'0'][i]);
        }
        return;
    }
};

/*
clarification questions:

string is given
string will be all digits? 2-9? yes
string digit can it be empty? yes then empty vector
constraints => length of digit ? = 4
can there be duplicate digits like 22 => ab,ac,ba,bc,ca,cb

global => map<char,vector<char>> mp, vector<string>
          vector<string> ans
States => 
index of digits, current string

base case => index of digits gets exhausted (add curr string to global ans variable)

without memoization => 4 positions to fill 4 => 4*4  

*/
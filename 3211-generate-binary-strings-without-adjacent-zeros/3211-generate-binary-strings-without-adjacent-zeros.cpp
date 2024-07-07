class Solution {
public:
    vector<string> ans;
    vector<string> validStrings(int n) {
        solve(n,0,"",0);
        return ans;
    }

    void solve(int n,int size,string curr,int streak){
        if(size==n){
            ans.push_back(curr);
            return;
        }

        if(streak==0){
            solve(n,size+1,curr+'0',1);
            solve(n,size+1,curr+'1',0);
        }
        else if(streak==1){
            solve(n,size+1,curr+'1',0);
        }
        return;
    }
};
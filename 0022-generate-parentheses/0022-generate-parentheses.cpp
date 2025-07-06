class Solution {
public:
    vector<string> ans;
    vector<string> generateParenthesis(int n) {
        string current="";
        generate(0,0,n,current);
        return ans;
    }

    void generate(int nOpen,int nClose,int n,string current){
        if(nOpen==n && nClose==n){
            ans.push_back(current);
            return;
        }
        if(nOpen<n){
            generate(nOpen+1,nClose,n,current+"(");
        }
        if(nClose<nOpen){
            generate(nOpen,nClose+1,n,current+")");
        }
        return;
    }
};
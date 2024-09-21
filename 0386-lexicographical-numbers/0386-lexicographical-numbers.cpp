class Solution {
public:
    vector<int> ans;
    vector<int> lexicalOrder(int n) {
        int digits = min(n,9);
        for(int i=1;i<=digits;i++){
            solve(i,n);
        }
        return ans;
    }

    void solve(int num,int n){
        if(num>n){
            return;
        }

        ans.push_back(num);
        for(int i=0;i<=9;i++){
            solve(num*10+i,n);
        }
        return;
    }
};
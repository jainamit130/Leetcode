class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> st;
        return solve(n,st);
    }

    bool solve(int n,unordered_set<int> st){
        if(n==1){
            return true;
        }
        if(st.find(n)!=st.end()){
            return false;
        }
        int sum=0;
        bool res=true;
        st.insert(n);
        while(n){
            sum+=pow(n%10,2);
            n/=10;
        }
        res=res&& solve(sum,st);
        return res;
    }
};
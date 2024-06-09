// class Solution {
// public:
//     int bulbSwitch(int n) {
        
//     }
// };


/*


2   4   6   8   10  12  14  16  18  20  22  24  26  28  30  32  34  36  38  40  42  44  46  48  50






*/


class Solution {
public:
    unordered_set<int> st;
    int bulbSwitch(int n) {
        for(int i=1;i<=n;i++){
            if(i%2!=0)
                st.insert(i);
        }
        solve(3,n,st);
        return st.size();
    }

    void solve(int currRound,int& n,unordered_set<int>& st){
        if(currRound>n){
            return;
        }

        for(int i=currRound;i<=n;i+=currRound){
            if(st.find(i)!=st.end()){
                st.erase(i);
            } else {
                st.insert(i);
            }
        }
        solve(currRound+1,n,st);
        return;
    }
};
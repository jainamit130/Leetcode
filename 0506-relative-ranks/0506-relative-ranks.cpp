class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<int> st(1000001,-1);
        for(int i=0;i<score.size();i++){
            st[score[i]]=i;
        }
        int k=1;
        vector<string> ans(score.size());
        for(int i=1000000;i>=0;i--){
            if(st[i]!=-1){
                if(k==1)
                    ans[st[i]]="Gold Medal";
                else if(k==2)
                    ans[st[i]]="Silver Medal";
                else if(k==3)
                    ans[st[i]]="Bronze Medal";
                else {
                    ans[st[i]]=to_string(k);
                }
                k++;
            }
        }
        return ans;
    }
};
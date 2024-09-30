class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        if(k==1){
            return 'a';
        }

        long long len = 1;
        int oper = -1;
        int newK = k;
        for(int i=0;i<operations.size();i++){
            len*=2;
            if(len>=k){
                oper=operations[i];
                newK = k-len/2;
                break;
            }
        }

        char ch = kthCharacter(newK,operations);
        if(oper){
            if(ch=='z'){
                return 'a';
            } else {
                return ch+1;
            }
        } else {
            return ch;
        }
    }
};
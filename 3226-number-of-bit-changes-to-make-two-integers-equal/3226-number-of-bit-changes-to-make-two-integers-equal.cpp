class Solution {
public:
    int minChanges(int n, int k) {
        int count=0;
        for(int i=0;i<32;i++){
            int bitn=1&(n>>i);
            int bitk=1&(k>>i);
            if(bitn==0 && bitk==1){
                return -1;
            }
            if(bitn==1 && bitk==0){
                count++;
            }
        }
        return count;
    }
};

/*

13

1   0   0   1

0   1   0   0

0   1   0   0


*/
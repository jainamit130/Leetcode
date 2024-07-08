class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> count(n);
        int choosenCount=0;
        int i=0;
        while(choosenCount!=n-1){
            int c=k-1;
            while(c){
                if(count[i]!=1){
                    c--;
                }
                i=(i+1)%n;
            }
            while(count[i]==1){
                i=(i+1)%n;
            }
            count[i]=1;
            choosenCount++;
            while(count[i]==1){
                i=(i+1)%n;
            }
        }
        return i+1;
    }
};
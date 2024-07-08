class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int> q;
        for(int i=1;i<=n;i++){
            q.push(i);
        }

        while(q.size()!=1){
            int c=k-1;
            while(c){
                int t=q.front();
                q.pop();
                q.push(t);
                c--;
            }
            q.pop();
        }
        return q.front();
    }
};
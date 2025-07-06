class Solution {
public:
    int findTheWinner(int n, int k) {
        return solve(n,k)+1;
    }

    int solve(int n,int k){
        if(n==0){
            return 0;
        }

        int index=(solve(n-1,k)+k)%n;
        return index;
    }
};

// class Solution {
// public:
//     int findTheWinner(int n, int k) {
//         queue<int> q;
//         for(int i=1;i<=n;i++){
//             q.push(i);
//         }

//         while(q.size()!=1){
//             int c=k-1;
//             while(c){
//                 int t=q.front();
//                 q.pop();
//                 q.push(t);
//                 c--;
//             }
//             q.pop();
//         }
//         return q.front();
//     }
// };


// class Solution {
// public:
//     int findTheWinner(int n, int k) {
//         vector<int> count(n);
//         int choosenCount=0;
//         int i=0;
//         while(choosenCount!=n-1){
//             int c=k-1;
//             while(c){
//                 if(count[i]!=1){
//                     c--;
//                 }
//                 i=(i+1)%n;
//             }
//             while(count[i]==1){
//                 i=(i+1)%n;
//             }
//             count[i]=1;
//             choosenCount++;
//             while(count[i]==1){
//                 i=(i+1)%n;
//             }
//         }
//         return i+1;
//     }
// };
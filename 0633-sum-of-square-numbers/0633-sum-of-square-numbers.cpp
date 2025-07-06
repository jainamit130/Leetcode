class Solution {
public:
    bool judgeSquareSum(int c) {
        int a=0;
        int b=sqrt(c);
        while(a<=b){
            long long ans = ((long long)a*a+(long long)b*b);
            if(ans==c)
                return true;
            if(ans<c){
                a++;
            } else {
                b--;
            }
        }
        return false;
    }
};

/*

1000000

10*10+100*100

*/

// class Solution {
// public:
//     bool judgeSquareSum(int c) {
//         for(int a=0;a<=c;a++){
//             int t=c-((long long)a*a);
//             if(t<0)
//                 break;
//             int b=sqrt(t);
//             if(((long long)a*a+(long long)b*b)==c)
//                 return true;
//         }
//         return false;
//     }
// };
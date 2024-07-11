class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),[](auto lhs,auto rhs){
            auto countt=[](int n){
                int c=0;
                for(int i=0;i<32;i++){
                    if(((n>>i)&1)==1){
                        c++;
                    }
                }
                return c;
            };
            int countl=countt(lhs);
            int countr=countt(rhs);
            if(countl==countr){
                return lhs<rhs;
            } else {
                return countl<countr;
            }
        });
        return arr;
    }
};
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int sum=0;
        for(int i=0;i<customers.size();i++){
            sum+=customers[i]*(!grumpy[i]);
        }
        int i=0,j=0;
        int ans=INT_MIN;
        while(j<customers.size()){
            if(j-i+1<=minutes){
                sum+=customers[j]*grumpy[j];
                j++;
            } else {
                sum-=customers[i]*grumpy[i];
                i++;
            }
            ans=max(ans,sum);
        }
        return ans;
    }
};


/*


1   0   1   2   1   1   7   5

0   1   0   1   0   1   0   1

i
    j

0
2
2
3
1
6

*/
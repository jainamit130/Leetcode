class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int sum=0;
        for(int i=0;i<customers.size();i++){
            if(grumpy[i]==0){
                sum+=customers[i];
            }
        }
        int i=0,j=0;
        int ans=INT_MIN;
        int add = 0;
        while(j<customers.size()){
            if(j-i+1<=minutes){
                if(grumpy[j]==1){
                    add+=customers[j];
                } 
                j++;
            } else {
                add-=customers[i]*grumpy[i];
                i++;
                add+=customers[j]*grumpy[j];
                j++;
            }
            ans=max(ans,sum+add);
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
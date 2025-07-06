class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long totalChalksToBeUsed = 0;
        for(int i=0;i<chalk.size();i++){
            totalChalksToBeUsed=totalChalksToBeUsed+chalk[i];
            if(totalChalksToBeUsed>k){
                return i;
            }
        }

        k=k-((long long)(k/totalChalksToBeUsed)*(long long)totalChalksToBeUsed);
        for(int i=0;i<chalk.size();i++){
            k-=chalk[i];
            if(k<0){
                return i;
            }
        }
        return 0;
    }
};
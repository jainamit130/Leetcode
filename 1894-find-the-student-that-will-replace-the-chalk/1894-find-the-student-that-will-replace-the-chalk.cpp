class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int totalChalksToBeUsed = 0;
        for(int i=0;i<chalk.size();i++){
            totalChalksToBeUsed+=chalk[i];
            if(totalChalksToBeUsed>=k){
                return i;
            }
        }

        k=k-((k/totalChalksToBeUsed)*totalChalksToBeUsed);
        for(int i=0;i<chalk.size();i++){
            k-=chalk[i];
            if(k<0){
                return i;
            }
        }
        return 0;
    }
};
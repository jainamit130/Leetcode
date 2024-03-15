//Brute Force
class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        unordered_map<int,int> currentAllot;
        for(int i=0;i<row.size();i++){
            currentAllot[row[i]]=i;
        }
        int ans=0;
        for(int i=0;i<row.size()-1;i+=2){
            int a,b;
            if(row[i]%2==0){
                a=row[i];
                b=row[i]+1;
            } else {
                a=row[i];
                b=row[i]-1;
            }
            if(row[i+1]!=b){
                int tempIndex=currentAllot[b];
                int temp=row[i+1];
                currentAllot[b]=i+1;
                currentAllot[row[i+1]]=tempIndex;
                row[i+1]=b;
                row[tempIndex]=temp;
                ans++;
            }
        }
        return ans;
    }
};
class Solution {
public:
    int maxPossibleScore(vector<int>& start, int d) {
        sort(start.begin(),start.end());
        int end = start.back()+d-start[0];
        int beg = INT_MAX;
        for(int i=1;i<start.size();i++){
            beg=min(max(start[i]-(start[i-1]+d),0),beg);
            if(beg==0){
                break;
            }
        }
        int ans=INT_MIN;
        while(beg<=end){
            int mid = beg+(end-beg)/2;
            if(isPossible(start,d,mid)){
                ans=max(mid,ans);
                beg=mid+1;
            } else {
                end=mid-1;
            }
        }
        return ans;
    }

    bool isPossible(vector<int>& start,int d,int minDiff){
        long long choosen = start[0]+minDiff;
        for(int i=1;i<start.size();i++){
            if(start[i]+d>=choosen){
                choosen=max(choosen,(long long)start[i])+minDiff;
            } else {
                return false;
            }
        }
        return true;
    }
};



/*





*/
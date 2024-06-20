class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int ans = 1;
        int startForce=1,endForce=position.back()-startForce;
        while(startForce<=endForce){
            int maxForce = startForce+(endForce-startForce)/2;
            if(positioned(position,maxForce,m-1)){
                ans=max(ans,maxForce);
                startForce = maxForce+1;
            } else {
                endForce = maxForce-1;
            }
        }
        return ans;
    }

    bool positioned(vector<int>& position,int maxForce,int m){
        int last=position[0];
        for(int i=1;i<position.size() && m>0;i++){
            if(position[i]-last>=maxForce){
                last=position[i];
                m--;
            }
        }
        return m<=0;
    }
};
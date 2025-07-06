class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        unordered_map<double,int> mp;

        mp[findDistance(p1,p2)]++;
        mp[findDistance(p1,p3)]++;
        mp[findDistance(p1,p4)]++;
        mp[findDistance(p2,p3)]++;
        mp[findDistance(p2,p4)]++;
        mp[findDistance(p3,p4)]++;
        if(mp.size()!=2){
            return false;
        }
        for(auto [a,b]:mp){
            if(a==0){
                return false;
            }
            if(b==4 || b==2){
                continue;
            } else {
                return false;
            }
        }
        return true;
    }

    double findDistance(vector<int>& a,vector<int>& b){
        int ax=a[0];
        int ay=a[1];

        int bx=b[0];
        int by=b[1];

        double dist=sqrt(pow(abs(ax-bx),2)+pow(abs(ay-by),2));
        return dist;
    }
};
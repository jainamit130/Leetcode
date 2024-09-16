class Solution {
public:
    int getTime(string time){
        return (time[0]-48)*10 + (time[1]-48);
    }
    int findMinDifference(vector<string>& timePoints) {
        sort(timePoints.begin(),timePoints.end(),[&](auto& lhs,auto& rhs){
            int hour1 = getTime(lhs.substr(0,2));
            int hour2 = getTime(rhs.substr(0,2));
            int min1 = getTime(lhs.substr(3));
            int min2 = getTime(rhs.substr(3));
            return (hour1*60+min1)<(hour2*60+min2);
        });
        int ans=INT_MAX;
        for(int i=0;i<timePoints.size();i++){
            int j=(i+1)%timePoints.size();
            int hour1 = getTime(timePoints[j].substr(0,2));
            int min1 = getTime(timePoints[j].substr(3));
            int time1 = hour1*60+min1;

            int hour2 = getTime(timePoints[i].substr(0,2));
            int min2 = getTime(timePoints[i].substr(3));
            int time2 = hour2*60+min2;
            
            //making both 0
            int diff = 1440-max(time1,time2)+min(time1,time2);


            //making both 
            ans=min(ans,min(diff,abs(time2-time1)));
        }
        return ans;
    }
};
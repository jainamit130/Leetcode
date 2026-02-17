class Solution {
public:
    unordered_set<string> ans;
    vector<string> readBinaryWatch(int turnedOn) {
        vector<int> hours = {8,4,2,1};
        vector<int> minutes = {32,16,8,4,2,1};
        solve(turnedOn,hours,minutes,0,0,-1,-1);
        vector<string> result(ans.begin(),ans.end());
        return result;
    }

    void solve(int turnedOn,vector<int>& hours,vector<int>& minutes,int h,int m,int hIndex,int mIndex) {
        if(turnedOn<0) return; 
        if(turnedOn==0) {
            if(h>=0 && h<=11 && m>=0 && m<=59) {
                string ho = to_string(h);
                string mi = (m<10? "0":"") + to_string(m);
                ans.insert(ho+":"+mi);
            }
            return;
        }
        for(int i=hIndex+1;i<hours.size();i++) {
            solve(turnedOn-1,hours,minutes,h+hours[i],m,i,mIndex);
            solve(turnedOn,hours,minutes,h,m,i,mIndex);
        }

        for(int i=mIndex+1;i<minutes.size();i++) {
            solve(turnedOn-1,hours,minutes,h,m+minutes[i],hIndex,i);
            solve(turnedOn,hours,minutes,h,m,hIndex,i);
        }
        return;
    }
};

/*

hours - 1   2   3
minutes - 1   2  3  4  5



*/
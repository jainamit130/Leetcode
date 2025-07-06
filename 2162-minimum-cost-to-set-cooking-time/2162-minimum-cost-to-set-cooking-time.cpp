class Solution {
public:
    int minCostSetTime(int startAt, int moveCost, int pushCost, int target) {
        int minutes = min(target/60,99);
        int seconds = target%60 + max((target/60-99)*60,0);
        int ans = 0;
        int ans2 = -1;
        char curr = to_string(startAt)[0];
        if(minutes!=0) {
            ans+=calcCost(to_string(minutes),curr,moveCost,pushCost);
            ans+=calcCost("0"+to_string(seconds),curr,moveCost,pushCost);
        } else {
            ans+=calcCost(to_string(seconds),curr,moveCost,pushCost);
        }

        curr = to_string(startAt)[0];
        if(minutes!=0 && seconds<=39) {
            ans2=0;
            if(minutes>1) {
                ans2+=calcCost(to_string(minutes-1),curr,moveCost,pushCost);
                ans2+=calcCost("0"+to_string(seconds + 60),curr,moveCost,pushCost);
            } else {
                ans2+=calcCost(to_string(seconds + 60),curr,moveCost,pushCost);
            }
        }
        if(ans2!=-1) {
            ans = min(ans,ans2);
        }
        return ans;
    }

    int calcCost(string nums,char& curr,int moveCost,int pushCost) {
        int cost = 0;
        int index = nums.size()>2?1:0;
        while(index<nums.size()) {
            if(curr!=nums[index]) {
                cost+=moveCost;
                curr = nums[index];
            }
            cost+=pushCost;
            index+=1;
        }
        return cost;
    }
};


/*
target/60 target%60 => (target/60)-1  (target%60)+60 (if target%60 <=39)  

x min
y sec


range target = 0min 1s ->  99mins 99s





*/
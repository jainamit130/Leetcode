class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_map<int,unordered_map<bool,int>> streaks;
        pair<int,int> maxStreakOdd={0,0};
        pair<int,int> maxStreakEven={0,0};
        for(int i=0;i<nums.size();i++){
            if(i%2==0)
                streaks[nums[i]][true]++;
            else
                streaks[nums[i]][false]++;

            if(maxStreakOdd.second<streaks[nums[i]][false])
                maxStreakOdd={nums[i],streaks[nums[i]][false]};

            if(maxStreakEven.second<streaks[nums[i]][true])
                maxStreakEven={nums[i],streaks[nums[i]][true]};
        }
        if(maxStreakOdd.first==maxStreakEven.first){
            streaks.erase(maxStreakOdd.first);
            if(!streaks.size()){
                return nums.size()/2;
            }
            int secondMaxOdd=0;
            int secondMaxEven=0;
            for(auto [a,c]:streaks){
                for(auto [EveOrNot,count]:c){
                    if(EveOrNot){
                        secondMaxEven=max(secondMaxEven,count);
                    } else {
                        secondMaxOdd=max(secondMaxOdd,count);
                    }
                }
            }
            int t=max(maxStreakEven.second+secondMaxOdd,maxStreakOdd.second+secondMaxEven);
            return nums.size()-t;
        }
        return nums.size()-maxStreakOdd.second-maxStreakEven.second;
    }
};
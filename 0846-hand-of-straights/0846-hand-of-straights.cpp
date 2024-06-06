class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int,int> mp;
        int t=0;
        if(hand.size()%groupSize==0){
            t=hand.size()/groupSize;
        } else {
            return false;
        }
        for(int i=0;i<hand.size();i++){
            mp[hand[i]]++;
            if(mp[hand[i]]>t)
                return false;
        }
        while(mp.size()){
            int curr = mp.begin()->first;
            for(int i=0;i<groupSize;i++){
                if(mp[curr+i]==0){
                    return false;
                } else {
                    mp[curr+i]--;
                    if(mp[curr+i]<=0){
                        mp.erase(curr+i);
                    }
                }
            }
        }
        return true;
    }
};

/*

1   2   3   6   2   3   4   7   8

1   2   2   3   3   4   6   7   8


1   2   3   4   6   7   8
1   2   2   1   1   1   1
i
j


1   2   3   4   6   7   8
0   0   0   0   1   1   1
                i
                        j

*/
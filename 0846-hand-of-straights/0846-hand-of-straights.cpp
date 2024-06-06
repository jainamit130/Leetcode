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
            map<int, int>::iterator it=mp.begin();
            int last=it->first;
            // cout<<last<<endl;
            it->second--;
            // cout<<it->first<<" "<<it->second<<endl;
            map<int, int>::iterator copyIt=it;
            copyIt++;
            if(mp[it->first]==0){
                mp.erase(it->first);
            } 
            it=copyIt;
            for(int i=1;i<groupSize;i++){
                if(last+1!=it->first){
                    return false;
                }
                it->second--;
                // cout<<it->first<<" "<<it->second<<endl;
                last=it->first;
                map<int, int>::iterator copyIt=it;
                copyIt++;
                if(mp[it->first]==0){
                    mp.erase(it->first);
                } 
                it=copyIt;
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
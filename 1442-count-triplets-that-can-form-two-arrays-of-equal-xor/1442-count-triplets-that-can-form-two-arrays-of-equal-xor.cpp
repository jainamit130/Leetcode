class Solution {
public:
    int countTriplets(vector<int>& arr) {
        vector<int> prefix(arr.size()+1);
        for(int i=0;i<arr.size();i++){
            prefix[i+1]=prefix[i]^arr[i];
        }
        unordered_map<int,vector<int>> history;
        history[0].push_back(0);
        int ans=0;
        for(int i=0;i<arr.size();i++){
            if(history.find(prefix[i+1])!=history.end()){
                for(auto j:history[prefix[i+1]]){
                    ans+=(i-j);
                }
            } 
            history[prefix[i+1]].push_back(i+1);
        }
        return ans;
    }
};

/*

0   1   2   3   4   5
0   1   0   1   0   1
                    i

ans = (1-0)+(2-1)+((3-0)+(3-2))+((4-1)+(4-3)) = 0 + 1 + 1 + 3 + 1 + 3 + 1 = 10

Map
0 -> 0,2,4
1 -> 1,3

*/
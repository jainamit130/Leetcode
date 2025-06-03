class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int n = status.size();
        vector<int> openable = status;
        int ans = 0;
        queue<int> q;
        for(auto box:initialBoxes) {
            q.push(box);
        }
        
        while(!q.empty()) {
            int size = q.size();
            vector<int> repeat;
            for(int i=0;i<size;i++) {
                int box = q.front();
    
                if(openable[box]) {
                    q.pop();
                    ans+=candies[box];
                    for(int i=0;i<keys[box].size();i++) {
                        openable[keys[box][i]]=1;
                    }
                    for(int i=0;i<containedBoxes[box].size();i++) {
                        q.push(containedBoxes[box][i]);
                    }
                } else {
                    q.pop();
                    repeat.push_back(box);
                }
            }
            if(repeat.size()==size) break;
            for(auto box:repeat) q.push(box);
        }
        return ans;
    }
};
class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<int> intervals1;
    }
};


/*

[1,0,5,2],[0,2,2,4],[3,2,5,3],[0,4,4,5]



horIntervals  = [0,2], [2,4], [3,5], [5,6]
vertIntervals  = [1,5], [0,2], [3,5], [0,4]

sort asc on 0th index and if first element equal then sort on 2nd element in desc 
Do the same for both intervals



*/


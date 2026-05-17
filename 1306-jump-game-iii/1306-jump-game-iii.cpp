class Solution {
public:
    vector<bool> visited;
    bool canReach(vector<int>& arr, int start) {
        visited.resize(arr.size(),false);
        return dpCanReach(arr,start);
    }

    bool dpCanReach(vector<int>& arr,int index) {
        if(index<0 || index>=arr.size() || visited[index]) return false;
        if(arr[index]==0) return true;
        visited[index]=true;
        return dpCanReach(arr,index+arr[index]) || dpCanReach(arr,index-arr[index]);
    }
};


/*

DP Approach

Tracking parameters

just index
cell already visited

*/
class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(capacity.begin(),capacity.end(),greater<int>());
        int sum=0;
        int count=0;
        for(auto n:apple)
            sum+=n;
        for(auto n1:capacity){
            sum-=n1;
            count++;
            if(sum<=0)
                break;
        }
        return count;
    }
};
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        unordered_map<int,int> memory;
        for(auto n:nums)
            memory[n]++;
        int count=0;
        for(auto n:nums){
            if(n>=k)
                break;
            if((memory.find(n)!=memory.end() && memory.find(k-n)!=memory.end())){
                memory[n]--;
                memory[k-n]--;
                if(n==k-n && memory[k-n]<=0){
                    memory.erase(n);
                    continue;
                }
                count++;
                if(memory[n]<=0){
                    memory.erase(n);
                    memory.erase(k-n);
                }
            }
            if(memory.size()==0)
                break;
        }
        return count;
    }
};
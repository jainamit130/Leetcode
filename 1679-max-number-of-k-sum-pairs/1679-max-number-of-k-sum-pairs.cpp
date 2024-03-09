class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        unordered_map<int,int> memory;
        for(auto n:nums){
            if(n<=k)
                memory[n]++;
        }
        int count=0;
        for(auto n:nums){
            if((n!=k-n && memory.find(n)!=memory.end() && memory.find(k-n)!=memory.end()) || (n==k-n && memory.find(n)!=memory.end() && memory[n]>=2)){
                memory[n]--;
                memory[k-n]--;
                count++;
                if(memory[n]<=0)
                    memory.erase(n);
                if(memory[k-n]<=0)
                    memory.erase(k-n);
            } else {
                memory.erase(n);
                memory.erase(k-n);
            }
            if(memory.size()==0)
                break;
        }
        return count;
    }
};
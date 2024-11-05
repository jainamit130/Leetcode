class Solution {
public:
    vector<int> indexes;
    Solution(vector<int>& w) {
        int sum = accumulate(w.begin(),w.end(),0);
        for(int index=0;index<w.size();index++){
            int times = (w[index]/(double)sum)*1000;
            for(int i=1;i<=times;i++){
                indexes.push_back(index);
            }
        }
    }
    
    int pickIndex() {
        if(indexes.size()==0){
            return 0;
        }
        return indexes[rand()%indexes.size()];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();



 2  5
2/7=29%     5/7=71%

 



 */
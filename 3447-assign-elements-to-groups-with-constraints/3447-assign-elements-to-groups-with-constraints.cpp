class Solution {
public:
    vector<int> assignElements(vector<int>& groups, vector<int>& elements) {
        int maxElement = *max_element(groups.begin(),groups.end());
        vector<int> factorsIndex(maxElement+1,-1);
        for(int i=0;i<elements.size();i++) {
            int num = elements[i];
            if(maxElement+1<=num || factorsIndex[num]!=-1) continue;
            for(int j = num; j <maxElement+1; j+=num) {
                if(factorsIndex[j]!=-1) continue;
                factorsIndex[j]=i;
            }
        }

        for(int i=0;i<groups.size();i++) {
            groups[i] = factorsIndex[groups[i]];
        }
        return groups;
    }
};



/*
0   0   -1  1  0 
8   4   3   2  4

0   1
4   2

[0 - max_elment of groups]



*/
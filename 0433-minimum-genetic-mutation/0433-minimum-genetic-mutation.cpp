class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> bankSet(bank.begin(),bank.end());
        vector<char> geneChar = {'A','C','G','T'}; 
        queue<string> q;
        q.push(startGene);
        int ans = 0;
        while(!q.empty()) {
            int size = q.size();
            while(size) {
                string currGene = q.front();
                q.pop();
                size--;
                if(currGene==endGene) return ans;
                for(int index=0;index<currGene.length();index++) {
                    for(int i=0;i<geneChar.size();i++) {
                        if(geneChar[i]!=currGene[index]) {
                            string temp = currGene;
                            temp[index] = geneChar[i];
                            if(bankSet.find(temp)!=bankSet.end()) {
                                q.push(temp);
                                bankSet.erase(temp);
                            } 
                        }
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};

/*






*/
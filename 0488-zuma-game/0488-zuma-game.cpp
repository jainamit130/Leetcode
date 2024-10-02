class Solution {
    unordered_map<char,int> mp;
    int mins=10000;
    string boa;
public:
    void addb(int i,int j,char c){
        boa.insert(i,j,c);
    }
    
    void del(int i,int j){
        boa.erase(boa.begin()+i,boa.begin()+j);
    }
    
    void dfs(int used){
        if(boa.empty()){
            mins=min(mins,used);
            return;
        }
        for(int i=0;i<boa.size();){
            int j=i;
            char c=boa[i];
            while(j<boa.size() && boa[j]==c){
                j++;
            }
            if((j-i)<3){
                int req=3-(j-i);
                if(mp[c]>=req){
                    del(i,j);
                    mp[c]-=req;
                    dfs(used+req);
                    mp[c]+=req;
                    addb(i,j-i,c);
                }
            }
            else{
                del(i,j);
                dfs(used);
                addb(i,j-i,c);
            }
            i=j;
        }
    }
    
    int findMinStep(string board, string hand) {
        for(auto h:hand){
            mp[h]++;
        }
        boa=board;
        dfs(0);
        return mins==10000 ? -1 : mins;
    }
};
/*

WRBRW

W   R   R   B   B  W

W1  R3  B2  W1

W1  W or R  R3  R or B  B2  B or W  W1


*/
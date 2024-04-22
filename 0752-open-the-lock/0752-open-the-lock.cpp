class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead;
        for(auto d:deadends)
            dead.insert(d);
        queue<string> q;
        q.push("0000");
        int level=0;
        while(!q.empty()){
            int size=q.size();
            while(size){
                string curr=q.front();
                q.pop();
                size--;
                if(curr==target)
                    return level;
                if(dead.find(curr)!=dead.end())
                    continue;
                dead.insert(curr);
                for(int i=0;i<curr.size();i++){
                    string newStr=curr;
                    if(newStr[i]=='9')
                        newStr[i]='0';
                    else 
                        newStr[i]=curr[i]+1;
                    q.push(newStr);
                    newStr=curr;
                    if(newStr[i]=='0')
                        newStr[i]='9';
                    else 
                        newStr[i]=curr[i]-1;
                    q.push(newStr);
                }
            }
            level++;
        }
        return -1;
    }
};


/*
deadends = ["0002","0001","0004","0040","0025"] 
target = "0003"

00
10
11
12
13
03







*/
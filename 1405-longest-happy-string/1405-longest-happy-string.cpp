class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<vector<int>> pq;
        if(a>0)
            pq.push({a,0});
        if(b>0)
            pq.push({b,1});
        if(c>0)
            pq.push({c,2});
        string ans="";
        while(pq.size()>1){
            int index = pq.top()[1];
            int count = pq.top()[0];
            pq.pop();
            int repeat = min(2,count);
            int nextIndex=-1;
            int nextCount=-1;
            int nextRepeat=-1;
            if(!pq.empty()){
                nextIndex = pq.top()[1];
                nextCount = pq.top()[0];
                nextRepeat = count-repeat<nextCount?min(2,nextCount):1;
            }

            ans+=(char)(index+'a');
            if(repeat==2){
                ans+=(char)(index+'a');
                if(nextIndex>=0){
                    ans+=(char)(nextIndex+'a');
                    if(nextRepeat==2){
                        ans+=(char)(nextIndex+'a');
                    }
                    pq.pop();
                    if(nextCount>nextRepeat)
                        pq.push({nextCount-nextRepeat,nextIndex});
                }
            }
            if(count>repeat)
                pq.push({count-repeat,index});
        }

        if(!pq.empty()){
            int index = pq.top()[1];
            int count = pq.top()[0];
            int repeat = min(count,2);
            ans+=(char)(index+'a');
            if(repeat==2){
                ans+=(char)(index+'a');
            }
        }
        return ans;
    }
};
class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> q;
        int zeros=0,ones=0;
        for(auto s:students){
            q.push(s);
            if(s==0)
                zeros++;
            else
                ones++;
        }
        for(int i=0;i<sandwiches.size();){
            int studAtFront=q.front();
            int topSand=sandwiches[i];
            if(zeros==0 && topSand==0)
                break;
            else if(ones==0 && topSand==1)
                break;
            if(studAtFront==topSand){
                i++;
                if(topSand==1)
                    ones--;
                else
                    zeros--;
                q.pop();
            } else {
                q.pop();
                q.push(studAtFront);
            }
        }
        return q.size();
    }
};
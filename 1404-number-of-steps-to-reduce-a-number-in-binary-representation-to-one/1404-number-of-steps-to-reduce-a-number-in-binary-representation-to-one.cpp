class Solution {
public:
    int numSteps(string s) {
        int steps = 0;
        while(s.length()>0 && s!="1") {
            if(s.back()=='1') {
                string endStr = "";
                while(s.length() && s.back()=='1') {
                    endStr += '0';
                    s.pop_back();
                }
                string midStr = "";
                if(s.length()>0) {
                    s.pop_back();
                    midStr = "1"; 
                }
                s = s + midStr + endStr;
            } else {
                s.pop_back();
            }
            steps++;
        }
        return steps;
    }
};

/*
1   1   0   1

1   1   1   0
1   1   1
1   0   0   0
1   0   0
1   0
1   0


1   0   0   1   1   

0   0

*/
class Solution {
public:
    int maxDiff(int num) {
        string numStr = to_string(num);
        return getA(numStr)-getB(numStr);
    }

    int getA(string numStr) {
        char from = numStr[0];
        for(auto ch:numStr) {
            if(ch!='9') {
                from = ch;
                break;
            }
        }
        return changeNumStr(numStr,from,'9');
    }

    int getB(string numStr) {
        if(numStr.length()==1) return 1;
        char from = numStr[0];
        char to = '1';
        if(from=='1') {
            to = '0';
            for(int i=1;i<numStr.length();i++) {
                char ch = numStr[i];
                if(ch!='0') {
                    from = ch;
                    break;
                }
            }
        }
        int b = changeNumStr(numStr,from,to);
        if(b==0) return stoi(numStr);
        return b;
    }

    int changeNumStr(string numStr,char from,char to) {
        for(auto& ch:numStr) {
            if(ch==from) ch=to;
        }
        return stoi(numStr);
    }
};


/*
9   2   8   8

*/
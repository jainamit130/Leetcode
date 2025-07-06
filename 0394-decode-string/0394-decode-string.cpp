class Solution {
public:
    string decodeString(string s) {
        stack<int> digits;
        stack<string> strs;
        return decode(s,0,0,"",digits,strs);
    }

    string decode(string s,int index,int number,string current, stack<int>& digits,stack<string>& strs){
        if(index>=s.length())
            return current;

        if(isdigit(s[index])){
            return decode(s,index+1,number*10+(s[index]-'0'),current,digits,strs);
        }
        
        if(s[index]=='['){
            digits.push(number);
            strs.push(current);
            return decode(s,index+1,0,"",digits,strs);
        }

        if(s[index]==']'){
            int times=digits.top();
            digits.pop();
            string repeated="";
            for(int i=1;i<=times;i++)
                repeated+=current;
            current=strs.top()+repeated;
            strs.pop();
            return decode(s,index+1,number,current,digits,strs);
        }
        return decode(s,index+1,number,current+s[index],digits,strs);
    }
};
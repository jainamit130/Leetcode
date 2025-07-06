class Solution {
public:
    string fractionAddition(string expression) {
        int n=expression.length();
        int ans1=0;
        int ans2=1;
        int ansSign=1;
        int num1=0;
        int num2=1;
        int opr=0;
        int sign=1;
        for(int i=0;i<n;i++){
            if(expression[i]=='-'){
                ans1=(ansSign)*(ans1*num2)+(sign)*(ans2*num1);
                ans2=ans2*num2;
                if(ans1<0){
                    ansSign=-1;
                    ans1=(-1)*ans1;
                } else {
                    ansSign=1;
                }
                sign=-1;
            } else if(expression[i]=='+'){
                ans1=(ansSign)*(ans1*num2)+(sign)*(ans2*num1);
                ans2=ans2*num2;
                if(ans1<0){
                    ansSign=-1;
                    ans1=(-1)*ans1;
                } else {
                    ansSign=1;
                }
                sign=1;
            } else if(expression[i]=='/'){
                opr=1;
            } else if(opr==0){
                num1=expression[i]-48;
                if(i+1<n && expression[i+1]=='0'){
                    num1=num1*10;
                    i++;        
                }
            } else if(opr==1){
                num2=expression[i]-48;
                if(i+1<n && expression[i+1]=='0'){
                    num2=num2*10;
                    i++;        
                }
                opr=0;
            }
        }
        ans1=(ansSign)*(ans1*num2)+(sign)*(ans2*num1);
        ans2=ans2*num2;
        if(ans1<0){
            ansSign=-1;
            ans1=(-1)*ans1;
        } else {
            ansSign=1;
        }
        string ans="";
        if(ansSign==-1){
            ans+="-";
        }
        if(ans1==0){
            ans2=1;
        } else {
            for(int i=min(ans1,ans2);i>=2;i--){
                if(ans1%i==0 && ans2%i==0){
                    ans1=(ans1/i);
                    ans2=(ans2/i);
                    break;
                }
            }
        }
        ans+=to_string(ans1)+"/"+to_string(ans2);
        return ans;
    }
};

/*
-1/6   +  1/3

-3+6/18

(ansSign)*num1 + (sign)*(ans1)/ans2*num2




*/

/*

-1/2+1/2




*/
class Solution {
public:
    string convertDateToBinary(string date) {
        int year = (date[0]-48)*1000 + (date[1]-48)*100 + (date[2]-48)*10 + (date[3]-48);
        int month = (date[5]-48)*10 + (date[6]-48);
        int day = (date[8]-48)*10 + (date[9]-48);
        return convertIntToBitsStr(year)+"-"+convertIntToBitsStr(month)+"-"+convertIntToBitsStr(day);
    }

    string convertIntToBitsStr(int num){
        string ans="";
        while(num){
            if(num&1){
                ans+="1";
            } else {
                ans+="0";
            }
            num=num>>1;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
class Solution {
public:
    string validIPAddress(string queryIP) {
        // Assume it to be a IPv6
        string query = "";
        int n = queryIP.length();
        int validation = -1;
        int count = 0;
        for(int i=0;i<=n;i++) {
            if(i<n && queryIP[i]!='.' && queryIP[i]!=':') {
                query+=queryIP[i];
            } else {
                count++;
                if(validation==-1 && i<n) validation = queryIP[i]=='.' ? 1 : 2; 
                if(validation!=0) validateLength(query,validation);
                if(validation!=0) validateLeadingZeros(query,validation);
                if(validation!=0) validateCharactersAndVal(query,validation);
                if(validation!=0 && i<n) validateDelimiter(queryIP[i],validation);
                if(validation==0) break;
                query="";
            }
        }
        if(!validation || (count!=4 && count!=8)) return "Neither";
        return validation==1 && count==4 ? "IPv4": "IPv6";
    }

    void validateLength(string query,int& validation) {
        int n = query.length();
        if(n<1 || n>4) validation = 0;
        return;
    }

    void validateLeadingZeros(string query,int& validation){
        int n = query.length();
        if(n>1 && query[0]=='0') validation = validation==2 ? 2 : 0;
        else if(validation==-1) validation = 2;
        return;
    }

    void validateCharactersAndVal(string query,int& validation) {
        int val = 0;
        for(auto ch:query) {
            if(validation==1) {
                if(isalpha(ch)) { validation = 0; return; }
                if(isdigit(ch)) val=val*10+(ch-'0');
            } else {
                if(isalpha(ch) && tolower(ch)<'a' || tolower(ch)>'f') { validation = 0; return; }
            }
        }
        if(validation==1 && (val<0 || val>255)) { validation = 0; return; }
        return;
    }

    void validateDelimiter(char ch,int& validation) {
        if(ch==':') validation = validation==2 ? 2 : 0;
        else if(ch=='.') validation = validation==1;
        return;
    }
};

/*

length 
isCharacter
leadingZeros




*/
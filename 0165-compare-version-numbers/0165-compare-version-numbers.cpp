class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i=-1;
        int j=-1;
        cout<<i<<" "<<j<<" "<<version1.length()<<" "<<version2.length()<<endl;
        
        while(i<version1.length() && j<version2.length()){
            cout<<i<<" "<<j<<endl;
            string num1="";
            string num2="";
            i++;
            while(version1[i]!='.'){
                num1+=version1[i];
                i++;
            }
            j++;
            while(version2[j]!='.'){
                num2+=version2[j];
                j++;
            }
            cout<<num1<<" "<<num2<<endl;
            int n1=strToNum(num1);
            int n2=strToNum(num2);
            if(n1<n2)
                return -1;
            else if(n1>n2)
                return 1;
        }
        string num1="";
        string num2="";
        while(i<version1.length()){
            cout<<"brooo";
            num1="";
            i++;
            while(version1[i]!='.'){
                num1+=version1[i];
                i++;
            }
            int n1=strToNum(num1);
            if(n1>0)
                return 1;
        }
        while(j<version2.length()){
            cout<<"brooo";
            num2="";
            j++;
            while(version2[j]!='.'){
                num2+=version2[j];
                j++;
            }
            int n2=strToNum(num2);
            if(n2>0)
                return -1;
        }
        return 0;
    }

    int strToNum(string n){
        int m=n.length()-1;
        int ans=0;
        for(int i=m;i>=0;i--){
            ans+=(n[m-i]*pow(10,i));
        }
        cout<<ans<<endl;
        return ans;
    }
};
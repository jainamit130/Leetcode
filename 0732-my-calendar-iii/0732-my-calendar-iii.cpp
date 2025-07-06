class MyCalendarThree {
public:
    map<int,int> mp;
    int maxi=0;
    MyCalendarThree() {
    }
    
    int book(int start, int end) {
        int sum=0;
        int ans=1;
        mp[start]++;
        mp[end]--;
        for(auto [a,b]:mp){
            sum+=b;
            if(start<=a && a<=end){
                ans=max(sum,ans);
            }
        }
        maxi=max(ans,maxi);
        ans=max(ans,maxi);
        return ans;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */


 /*
 
    10     20 
                            50            60
    10              40
5       15      
5   10
                25                 55




start before and end after
start between
end between



 */
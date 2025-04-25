class MKAverage {
public:
    multiset<int> large,mid,small;
    int m,k;
    int sum = 0;
    queue<int> q;
    MKAverage(int a, int b) { m=a;k=b; }

    void looseElement() {
        int num = q.front();
        q.pop();
        if(mid.find(num)!=mid.end()) {
            mid.erase(mid.find(num));
            sum-=num;
        }
        // try to remove from large
        else if(*large.begin()<=num) { 
            large.erase(large.find(num));
            large.insert(*mid.rbegin());
            sum-=*mid.rbegin();
            mid.erase(--mid.end());
        }
        // try to remove from small
        else if(*small.rbegin()>=num) { 
            small.erase(small.find(num));
            small.insert(*mid.begin());
            sum-=*mid.begin();
            mid.erase(mid.begin());
        } 
    }

    void gainElement(int num) {
        int midElement = num;
        // try to go into large
        if(*large.begin()<=num) {
            midElement = *large.begin();
            large.insert(num);
            large.erase(large.begin());
        }
        // try to go into small
        if(*small.rbegin()>=num) {
            midElement = *small.rbegin();
            small.insert(num);
            small.erase(--small.end());
        }
        // add num to mid
        if(q.size()>2*k) {
            mid.insert(midElement);
            sum+=1LL*midElement;
        }
    }

    void addElement(int num) {
        q.push(num);
        if(large.size()<k) {
            large.insert(num);
            small.insert(num);
        } else {
            // both large and small are of size k at this point and should be maintined
            if(q.size()==m+1) looseElement();
            gainElement(num);
        } 
    }
    
    int calculateMKAverage() {
        if(q.size()<m) return -1;
        return sum/mid.size();   
    }
};

/**
 * Your MKAverage object will be instantiated and called as such:
 * MKAverage* obj = new MKAverage(m, k);
 * obj->addElement(num);
 * int param_2 = obj->calculateMKAverage();
 */
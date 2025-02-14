class ProductOfNumbers {
public:
    vector<vector<int>> prefix;
    ProductOfNumbers() {
        prefix.push_back({1,0});
    }
    
    void add(int num) {
        if(num==0) {
            prefix.push_back({1,(int)prefix.size()});
        } else {
            prefix.push_back({prefix.back()[0]*num,prefix.back()[1]});
        }
    }
    
    int getProduct(int k) {
        int zeroIndex = prefix.back()[1];
        int index = prefix.size()-k-1;
        if(index<zeroIndex) {
            return 0;
        } 
        return prefix.back()[0]/prefix[index][0];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);



    3   0   2   5   4  =2  =3  =4  8  =2
1   3   1   2   10  40 20  
0   0   2   2   2   2   

 */
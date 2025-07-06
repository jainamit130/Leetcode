class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if(!flowerbed[0] && (flowerbed.size()==1 || !flowerbed[1])){
            flowerbed[0]=1;
            n--;
        }
        if(!flowerbed.back() && (flowerbed.size()==1 || !flowerbed[flowerbed.size()-2])){
            flowerbed[flowerbed.size()-1]=1;
            n--;
        }
        if(n<=0)
            return true;
        for(int i=0;i<flowerbed.size();i++){
            if(flowerbed[i]!=1){
                if(i-1>=0 && flowerbed[i-1]!=1 && i<flowerbed.size() && flowerbed[i+1]!=1){
                    flowerbed[i]=1;
                    n--;
                }
            }
        }
        if(n<=0)
            return true;
        return false;
    }
};
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = 0;
        int num = n;
        for(int i=0; i<flowerbed.size(); i++){
            if(flowerbed[i]==0){
                count++;
            }
            else{
                count = -1;
            }
            if (count ==2){
                num--;
                count = 0;
            }
        }
        if(count==1) num--;
        if (num<=0) return true;
        return false;
    }
};
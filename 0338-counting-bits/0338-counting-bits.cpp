class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> count(1,0);
        if(n==0) return count;
        for(int i=1; i<n+1; i++){ 
            int rem = 0;
            int quo = i;
            int temp =0;
            while(quo){
                rem = quo%2;
                quo = quo/2;
                if(rem==1) temp++;
            }
            count.push_back(temp);
        }
        return count;
    }
};
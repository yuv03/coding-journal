class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 2) return 0;
        // int frst = 0;
        int scnd = 1;
        int loww = prices[0];
        int maxx = 0;

        while(scnd<prices.size()){
            if(prices[scnd] > loww){
                maxx = max(maxx, prices[scnd]-loww);
                loww = min(loww , prices[scnd]);
                scnd++;
            } 
            else if (prices[scnd] <= loww){
                loww = min(loww , prices[scnd]);
                scnd++;
            }
        }
        return maxx;
    }
};

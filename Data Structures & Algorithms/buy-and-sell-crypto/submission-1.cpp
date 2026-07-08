class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int scnd = 1;
        int loww = prices[0];
        int maxx = 0;

        while(scnd<prices.size()){
                maxx = max(maxx, prices[scnd]-loww);
                loww = min(loww , prices[scnd]);
                scnd++;
        }
        return maxx;
    }
};

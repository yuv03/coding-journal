class Solution {
public:
    int f(int n, vector<int>& dp){
        if(dp[n]!=-1) return dp[n];
        if(n<=1) {
            dp[n] = n;
            return n;
        }
        dp[n] = f(n-1, dp) + f(n-2, dp);
        return dp[n];
    }

    int fib(int n) {
        vector<int> dp(n+1,-1);
        return f(n, dp);
        
    }
};
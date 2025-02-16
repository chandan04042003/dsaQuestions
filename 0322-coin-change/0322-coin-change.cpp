class Solution {
private:
    int func(vector<int>& coins, int i, int t, vector<vector<int>> &dp){
        if(t==0) return 0;
        if(i<0 || t<0) return INT_MAX-1;

        if(dp[i][t]!=-1) return dp[i][t];
        
        int not_pick= func(coins,i-1,t,dp);
        int pick= INT_MAX;
        if(t>= coins[i]){
            int res=func(coins,i,t-coins[i],dp);
            if(res!=INT_MAX-1) pick= 1+ res;
        }

        return dp[i][t]=min(pick,not_pick);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1,-1));
        int res = func(coins,n-1,amount,dp);
        return (res== INT_MAX - 1) ? -1 : res;
    }
};
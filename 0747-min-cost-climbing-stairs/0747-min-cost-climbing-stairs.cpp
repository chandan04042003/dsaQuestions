class Solution {
private:
    int helper(int i, vector<int>& cost, vector<int>& dp){
        if(i==0) return cost[0];
        if(i==1) return cost[1];
        if(i<0) return INT_MAX;

        if(dp[i]!=-1) return dp[i];

        // 1 step:-
        int oneStep = cost[i] + helper(i-1,cost,dp);
        int twoStep = cost[i] + helper(i-2,cost,dp);

        return dp[i]=min(oneStep,twoStep);

    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(n,-1);
        return min(helper(n-1, cost, dp), helper(n-2, cost, dp));
    }
};
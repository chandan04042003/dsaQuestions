class Solution {
private:
    int helper(int i, vector<int>& nums, vector<int>& dp){
        if(i==0) return nums[0];
        if(i==-1) return 0;

        if(dp[i]!=-1) return dp[i];

        // take
        int take= nums[i] + helper(i-2,nums,dp);
        // not_take
        int not_take= helper(i-1,nums,dp);

        return dp[i]=max(take,not_take); 
    }
public:
    int rob(vector<int>& nums) {
        int n= nums.size();
        vector<int> dp(n,-1);
        return helper(n-1,nums,dp);
    }
};
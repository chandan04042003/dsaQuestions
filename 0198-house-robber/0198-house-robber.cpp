class Solution {
private:
    int func(vector<int>& nums, int i,vector<int> &dp){
        if(i==0) return nums[0];
        if(i<0) return 0;

        if(dp[i]!=-1) return dp[i];

        int pick= nums[i]+func(nums,i-2,dp);
        int not_pick= func(nums,i-1,dp);

        return dp[i]=max(pick,not_pick);
    }
public:
    int rob(vector<int>& nums) {
        int n= nums.size();
        vector<int>dp(n,-1);
        return func(nums,n-1,dp);
    }
};
class Solution {
private:
    int countFn(int i,int j,vector<vector<int>>& dp){
        if(i<0||j<0) return 0;
        if(i==0 && j==0) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j]=countFn(i-1,j,dp)+countFn(i,j-1,dp);
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return countFn(m-1,n-1,dp);
    }
};
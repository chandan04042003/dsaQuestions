class Solution {
private:
    int minPathCal(vector<vector<int>>& grid,int i,int j,vector<vector<int>>& dp){
        if(i==0 && j==0) return grid[0][0];
        if(i<0 || j<0) return 1e9;
        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j]=grid[i][j]+min(minPathCal(grid,i-1,j,dp),minPathCal(grid,i,j-1,dp));
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return minPathCal(grid,n-1,m-1,dp);
    }
};
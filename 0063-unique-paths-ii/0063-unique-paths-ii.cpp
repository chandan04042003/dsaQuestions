class Solution {
private:
     int countFn(vector<vector<int>>& ob,int i,int j,vector<vector<int>>& dp){
        if(i>=0 && j>=0 && ob[i][j]==1) return 0;
        if(i<0||j<0) return 0;
        if(i==0 && j==0) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j]=countFn(ob,i-1,j,dp)+countFn(ob,i,j-1,dp);
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return countFn(obstacleGrid,m-1,n-1,dp);
    }
};
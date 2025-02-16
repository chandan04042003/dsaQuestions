class Solution {
private:
    void dfs(vector<vector<char>>& grid,vector<vector<bool>>& vis,int i,int j,int m,int n){
        if(i<0 || j<0 || i>m-1 || j>n-1 || vis[i][j] || grid[i][j]=='0' ) return;
        vis[i][j]=true;
        dfs(grid,vis,i-1,j,m,n);
        dfs(grid,vis,i,j+1,m,n);
        dfs(grid,vis,i+1,j,m,n);  
        dfs(grid,vis,i,j-1,m,n); 
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int m= grid.size();
        int n=grid[0].size();
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    dfs(grid,vis,i,j,m,n);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
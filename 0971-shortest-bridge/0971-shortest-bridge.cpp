class Solution {
private:
    void dfs(vector<vector<int>>& grid,vector<vector<bool>>& vis,int i,int j,queue<pair<int,int>> &q){
        int n = grid.size();
        int arr[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
        if(i<0 || i==n || j<0 || j==n || grid[i][j]==0 || vis[i][j]) return;
        vis[i][j]= true;
        q.push({i,j});
        for(int k=0;k<4;k++){
            int r= i+arr[k][0];
            int c=j+arr[k][1];
            dfs(grid,vis,r,c,q);
        }
    }
    int bfs(vector<vector<int>>& grid,vector<vector<bool>>& vis,queue<pair<int,int>> &q){
        int n= grid.size();
        int arr[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
        int steps=0;
        while(!q.empty()){
            int N= q.size();
            while(N--){
                int r=q.front().first;
                int c=q.front().second;
                q.pop();

                for(int k=0;k<4;k++){
                    int nr=r+arr[k][0];
                    int nc=c+arr[k][1];

                    if(nr>=0 && nr<n && nc>=0 && nc<n && !vis[nr][nc]){
                        if(grid[nr][nc]==1) return steps;
                        vis[nr][nc]=true;
                        q.push({nr,nc});
                    }
                }
            }
            steps++;
        }
        return -1;
    }
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int n= grid.size();
        bool found=false;
        vector<vector<bool>> vis(n,vector<bool>(n,false));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            if(found) break;
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    dfs(grid,vis,i,j,q);
                    found= true;
                    break;
                } 
            }
        }
        return bfs(grid,vis,q);
    }
};
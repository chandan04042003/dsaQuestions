class Solution {
private:
    int bfs(vector<vector<int>>& grid,vector<vector<bool>>& vis){
        int n=grid.size();
        int m=grid[0].size();
        int fresh=0;
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    vis[i][j]=true;
                    q.push({i,j});
                }
                if(grid[i][j]==1) fresh++; 
            }
        }
        int arr[4][2]={{0,-1},{-1,0},{0,+1},{+1,0}};
        int time=0;
        while(!q.empty()){
            int N=q.size();
            bool infected = false;
            while(N--){
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                for(auto& a:arr){
                    int dx=x+a[0];
                    int dy=y+a[1];
                    if(dx>=0 && dy>=0 && dx<n && dy<m && !vis[dx][dy] && grid[dx][dy]==1){
                        q.push({dx,dy});
                        vis[dx][dy]=true;
                        fresh--;
                        infected = true;
                    }
                }
            }  
            if (infected) time++;
        }
        return fresh == 0 ? time : -1;
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        return bfs(grid,vis);
    }
};
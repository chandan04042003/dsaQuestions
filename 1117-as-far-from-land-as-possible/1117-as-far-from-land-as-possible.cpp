class Solution {
private: 
    int bfs(vector<vector<int>>& grid){
        int n = grid.size();
        int steps=0;
        int maxi=-1;

        int land=0;
        int water=0;

        queue<pair<int,int>> q;
        vector<vector<bool>> vis(n,vector<bool>(n,false));

        int delCoor[4][2]={{-1,0},{0,1},{1,0},{0,-1}};

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    land++;
                    vis[i][j]=true;
                    q.push({i,j});
                } 
                else water++;
            }
        }

        // If all cells are land or all cells are water
        if(land == 0 || water == 0) return -1;

        while(!q.empty()){
            int N=q.size();
            while(N--){
                int r= q.front().first;
                int c= q.front().second;
                q.pop();

                for(auto [dr,dc]:delCoor){
                    int Nr = r+dr;
                    int Nc= c+dc;
                    if(Nr>=0 && Nr<n && Nc>=0 && Nc<n && !vis[Nr][Nc] && grid[Nr][Nc]==0){
                        vis[Nr][Nc]=true;
                        maxi=max(maxi,steps+1);
                        q.push({Nr,Nc});
                    }
                }
            }
            steps++;
        }
        return maxi;
    }
public:
    int maxDistance(vector<vector<int>>& grid) {
        return bfs(grid);
    }
};
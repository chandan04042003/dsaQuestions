class Solution {
private:
    int bfs(vector<vector<int>>& grid){
        int n= grid.size();
        // If start or end is blocked, return -1 immediately
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;

        int steps=0;

        int delCoor[8][2]={{-1,0},{-1,+1},{0,+1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};

        queue<pair<int,int>> q;
        vector<vector<bool>> vis(n,vector<bool>(n,false));
        
        q.push({0,0});
        vis[0][0]=true;

        while(!q.empty()){
            int N= q.size();
            while(N--){
                int r=q.front().first;
                int c=q.front().second;
                q.pop();
                
                if(r==n-1 && c==n-1) return steps+1;

                for(auto &[dr,dc]: delCoor){ // imp
                    int newR = r + dr;
                    int newC = c + dc;

                    if (newR >= 0 && newR < n && newC >= 0 && newC < n && !vis[newR][newC] 
                    && grid[newR][newC] == 0){ // imp
                        vis[newR][newC]=true;
                        q.push({newR,newC});
                    } 
                }
            }
            steps++;
        }
        return -1;
    }
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        return bfs(grid);
    }
};
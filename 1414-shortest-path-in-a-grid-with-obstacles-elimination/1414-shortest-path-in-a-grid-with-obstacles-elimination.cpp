class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n=grid[0].size();

        int steps = 0;
        vector<vector<vector<bool>>> vis(m, vector<vector<bool>>(n,vector<bool>(k+1,false))); 
        queue<vector<int>> q;

        int arr[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

        q.push({0, 0, k});
        vis[0][0][k] = true;

        while (!q.empty()) {
            int N = q.size();
            while (N--) {
                vector<int> vec=q.front();
                int r = vec[0];
                int c = vec[1];
                int d = vec[2];
                q.pop();

                if (r == m - 1 && c == n - 1) return steps; // Reached destination

                for (auto &[dr, dc] : arr) {
                    int Nr = r + dr;
                    int Nc = c + dc;

                    // Check bounds before accessing grid[Nr][Nc]
                    if (Nr >= 0 && Nr < m && Nc >= 0 && Nc < n) {
                        if(grid[Nr][Nc]==0 && !vis[Nr][Nc][d]){
                            q.push({Nr,Nc,d});
                            vis[Nr][Nc][d]=true;
                        }else if(grid[Nr][Nc]==1 && d>0 && !vis[Nr][Nc][d-1]){
                            q.push({Nr,Nc,d-1});
                            vis[Nr][Nc][d-1]=true;
                        }
                    }
                }
            }
            steps++;
        }
        return -1; // Destination not reachable
    }
};
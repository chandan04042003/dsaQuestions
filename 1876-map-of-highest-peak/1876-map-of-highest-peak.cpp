class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int arr[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        int n = isWater.size();
        int m = isWater[0].size();
        queue<pair<int, int>> q;
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        
        // Initialize the queue with water cells and set their height to 0
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (isWater[i][j] == 1) {
                    q.push({i, j});
                    isWater[i][j] = 0;
                    vis[i][j] = true;
                } else {
                    isWater[i][j] = INT_MAX; // Initialize land cells to a large value
                }
            }
        }
        
        // Perform BFS to assign heights
        while (!q.empty()) {
            int len = q.size();
            while (len--) {
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                int val1 = isWater[r][c];
                
                for (auto &[dr, dc] : arr) {
                    int nr = r + dr;
                    int nc = c + dc;
                    
                    // Check if the new cell is within bounds and hasn't been visited
                    if (nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc]) {
                        isWater[nr][nc] = val1 + 1; // Assign height
                        vis[nr][nc] = true; // Mark as visited
                        q.push({nr, nc}); // Add to queue
                    }
                }
            }
        }
        
        return isWater;
    }
};
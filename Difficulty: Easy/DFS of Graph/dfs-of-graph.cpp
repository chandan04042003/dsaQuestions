
class Solution {
private:
    void helper(int v, vector<vector<int>>& adj, vector<bool>& vis, vector<int>& ans) {
        ans.push_back(v);
        for (int n : adj[v]) {
            if (!vis[n]) {
                vis[n] = true;
                helper(n, adj, vis, ans);
            }
        }
    }

public:
    vector<int> dfs(vector<vector<int>>& adj) {
        int m = adj.size();
        vector<bool> vis(m, false);
        vector<int> ans;

        for (int i = 0; i < m; i++) {
            if (!vis[i]) {
                vis[i] = true;
                helper(i, adj, vis, ans);
            }
        }

        return ans;
    }
};


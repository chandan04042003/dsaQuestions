class Solution {
  private:
   bool dfs(int e,int p,vector<int>& vis,vector<vector<int>>& adj){
       // 1.
       vis[e]=true;
       for(int n:adj[e]){
           if(vis[n] && n!=p) return true;
           if(!vis[n] && dfs(n,e,vis,adj)) return true;
       }
       return false;
   }
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for(auto& vec:edges){
            int n1=vec[0];
            int n2=vec[1];
            adj[n1].push_back(n2);
            adj[n2].push_back(n1);
        }
        vector<int> vis(V,false);
        for(int i=0;i<V;i++){
            if (!vis[i] && dfs(i, -1, vis, adj)) return true;
        }
        return false;
    }
};
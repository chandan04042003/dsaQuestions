class Solution {
private:
    void dfsHelper(vector<vector<int>>& adj,int i,vector<int>& vis){
        for(int j:adj[i]){
            if(vis[j]!=1){
                vis[j]=1;
                dfsHelper(adj,j,vis);
            }
        }
    }
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        // adj list creation
        vector<vector<int>> adj(n);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]); // as undirected graph
        }
        vector<int> vis(n,0);
        vis[source]=1;
        dfsHelper(adj,source,vis);
        if(vis[destination]==1) return true;
        return false;
    }
};
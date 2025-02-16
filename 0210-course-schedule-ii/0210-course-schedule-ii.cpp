class Solution {
private:
    vector<int> topoKahn(int numCourses, vector<vector<int>>& prerequisites){
        vector<vector<int>> adj(numCourses);
        int n = prerequisites.size();
    
        for(int i=0;i<n;i++){
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }

        vector<int> indegree(numCourses, 0);
        for(int i=0;i<numCourses;i++){
            for(auto it:adj[i]){
                indegree[it]++;
            }
        }

        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0) q.push(i);
        }
        vector<int> topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for(auto it: adj[node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        reverse(topo.begin(),topo.end());
        if (topo.size() != numCourses) return {};
        return topo;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        return topoKahn(numCourses,prerequisites);
    }
};
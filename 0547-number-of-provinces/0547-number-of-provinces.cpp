class Solution {
private:
    void dfsHelper(int i,vector<vector<int>>& isConnected,vector<int>& vis){
        for(int j=0;j<isConnected.size();j++){
            if(isConnected[i][j]==1 && vis[j]!=1){
                vis[j]=1;
                dfsHelper(j,isConnected,vis);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int> vis(n,0);
        int cnt=0;
        for(int i=0;i<n;i++){
            if(vis[i]!=1){
                cnt++;
                dfsHelper(i,isConnected,vis);
            }
        }
        return cnt;
    }
};
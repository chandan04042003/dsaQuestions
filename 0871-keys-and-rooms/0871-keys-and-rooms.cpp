class Solution {
private:
    void dfsHelper(int i,vector<vector<int>>& rooms,vector<int>& vis){
        for(int j:rooms[i]){
            if(vis[j]!=1){
                vis[j]=1;
                dfsHelper(j,rooms,vis);
            }
        }
    }
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<int> vis(n,0);
        vis[0]=1;
        dfsHelper(0,rooms,vis);
        int i;
        for(i=0;i<n;i++){
            if(vis[i]!=1) break;
        }
        if(i<n) return false;
        return true;
    }
};
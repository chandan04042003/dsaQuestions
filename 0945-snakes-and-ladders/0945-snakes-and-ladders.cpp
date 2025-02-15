class Solution {
private:
    pair<int,int> getCoord(int val,int n){
        int r= (n-1)-((val-1)/n);
        int c= (val-1)%n;
        if((n+r)%2==0) c=(n-1)-c;

        // imp
        return make_pair(r,c);
    }

    int bfs(vector<vector<int>>& board){
        int n=board.size();
        int steps=0;
        queue<int> q;
        vector<vector<bool>> vis(n,vector<bool>(n,false));

        vis[n-1][0]=true;
        q.push(1);

        while(!q.empty()){
            int N= q.size();
            while(N--){
                int x= q.front();
                q.pop();

                if(x==n*n) return steps;  // imp

                for(int k=1;k<=6;k++){
                    int val=x+k;
                    if(val > n*n) break; // imp

                    pair<int,int> coord=getCoord(val,n);
                    int r= coord.first;
                    int c= coord.second;
                    
                    if(vis[r][c]) continue;
                    vis[r][c]=true;
                    if(board[r][c]!=-1) q.push(board[r][c]);
                    else q.push(val);
                }
            }
            steps++;
        }
        return -1;
    }
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        return bfs(board);
    }
};
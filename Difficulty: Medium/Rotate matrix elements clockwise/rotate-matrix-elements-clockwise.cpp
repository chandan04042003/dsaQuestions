// User function Template for C++

class Solution {
  public:
    vector<vector<int>> rotateMatrix(int M, int N, vector<vector<int>> Mat) {
        // even <n/2 works
        // odd <n/2 works --> skips one mid row
        int layers=min(M,N)/2;
        for(int k=0;k<layers;k++){
            int up=k;
            int down=M-1-k;
            int left=k;
            int right=N-k-1;
            
            int prev=Mat[up+1][left];
            
            for(int i=left;i<=right;i++){
                int curr=Mat[up][i];
                Mat[up][i]=prev;
                prev=curr;
            }
            
            for(int i=up+1;i<=down;i++){
                int curr=Mat[i][right];
                Mat[i][right]=prev;
                prev=curr;
            }
            
            for(int i=right-1;i>=left;i--){
                int curr=Mat[down][i];
                Mat[down][i]=prev;
                prev=curr;
            }
            
            for(int i=down-1;i>up;i--){
                int curr=Mat[i][left];
                Mat[i][left]=prev;
                prev=curr;
            }
        }
        return Mat;
    }
};
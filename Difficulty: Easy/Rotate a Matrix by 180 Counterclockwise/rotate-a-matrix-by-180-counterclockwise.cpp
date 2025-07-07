class Solution {
  public:
    void rotateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        for(auto& row:mat){
            reverse(row.begin(),row.end());
        }
        for(int i=0;i<n/2;i++){
            for(int j=0;j<n;j++){
                swap(mat[i][j],mat[n-1-i][j]);
            }
        }
    }
};
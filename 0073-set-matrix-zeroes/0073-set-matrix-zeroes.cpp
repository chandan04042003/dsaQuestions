class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<int>row;
        vector<int>col;
        int m=matrix.size();
        int n=matrix[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    row.push_back(i);
                    col.push_back(j);
                }
            }
        }
        for(int k=0;k<row.size();k++){
            for(int j=0;j<n;j++){
                matrix[row[k]][j]=0;
            }
        }
        for(int k=0;k<col.size();k++){
            for(int i=0;i<m;i++){
                matrix[i][col[k]]=0;
            }
        }
    }
};
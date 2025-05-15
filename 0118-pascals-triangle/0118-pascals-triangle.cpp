class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> arr(numRows,vector<int>(numRows,0));
        // using matrix representation
        vector<vector<int>> ans;
        for(int i=0;i<numRows;i++){
            arr[i][0]=1;
            arr[i][i]=1;
        }
        for(int i=2;i<numRows;i++){
            for(int j=1;j<i;j++){
                arr[i][j]=arr[i-1][j-1]+arr[i-1][j];
            }
        }
        for(int i=0;i<numRows;i++){
            vector<int> vec;
            for(int j=0;j<=i;j++){
                vec.push_back(arr[i][j]);
            }
            ans.push_back(vec);
        }
        return ans;
    }
};
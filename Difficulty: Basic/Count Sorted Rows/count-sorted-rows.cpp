// User function Template for C++

class Solution {
  public:
    int sortedCount(int N, int M, vector<vector<int>> Mat) {
        int cnt=0;
        for(auto& row:Mat){
            int n=row.size();
            int i=1;
            while(i<n && row[i-1]<row[i]) i++;
            if(i>=n){
                cnt++;
                continue;
            }
            i=1;
            while(i<n && row[i-1]>row[i]) i++;
            if(i>=n){
                cnt++;
                continue;
            }
        }
        return cnt;
    }
};
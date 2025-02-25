class Solution {
private:
    void helper(int i, int t, int k, vector<int>& arr, vector<vector<int>>& ans){
        if(arr.size()==k){
            if(t==0) ans.push_back(arr);
            return;
        }
        

        for(int j=i;j<=9;j++){
            if((t-j)<0) break;
            arr.push_back(j);
            helper(j+1,t-j,k,arr,ans);
            arr.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> arr; 
        vector<vector<int>> ans;
        if(((k*(k+1))/2)>n) return ans;
        helper(1,n,k,arr,ans);
        return ans;
    }
};
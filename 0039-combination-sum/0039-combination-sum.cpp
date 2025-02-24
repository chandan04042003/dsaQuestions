class Solution {
private:
    void helper(int i,int t, vector<int>& arr, vector<vector<int>>& ans, vector<int>& nums){
        if (t == 0) { 
            ans.push_back(arr);
            return;
        }
        if (i >= nums.size() || t < 0) return;

        arr.push_back(nums[i]);
        helper(i, t - nums[i], arr, ans, nums);
        arr.pop_back();

        helper(i + 1, t, arr, ans, nums);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        /* involves printing of 
        subsequences => backtracking */
        vector<int> arr;
        vector<vector<int>> ans;
        helper(0,target,arr,ans,candidates);
        return ans;
    }
};
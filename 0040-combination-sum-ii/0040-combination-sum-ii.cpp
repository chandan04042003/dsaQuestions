class Solution {
private:
    // void helper(int i,int t, vector<int>& arr, vector<vector<int>>& ans, vector<int>& nums){
    //     if (t == 0) {
    //         vector<int> temp = arr; 
    //         sort(temp.begin(), temp.end()); 
    //         if (find(ans.begin(), ans.end(), temp) == ans.end()) ans.push_back(temp);
    //         return;
    //     }
    //     if(i>=nums.size() || t<0) return;
        
    //     // take:
    //     arr.push_back(nums[i]);
    //     helper(i+1,t-nums[i],arr,ans,nums);
    //     // backtrack
    //     arr.pop_back();
    //     // not-take:
    //     helper(i+1,t,arr,ans,nums);
    // } -----> Time Limit Exceeded

    void helper(int i, int t, vector<int>& arr, vector<vector<int>>& ans, vector<int>& nums) {
        if (t == 0) { 
            ans.push_back(arr);
            return;
        }
        if (i >= nums.size() || t < 0) return;

        for (int j = i; j < nums.size(); j++) {
            if (j > i && nums[j] == nums[j - 1]) continue;

            arr.push_back(nums[j]); 
            helper(j + 1, t - nums[j], arr, ans, nums);
            arr.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> arr;
        vector<vector<int>> ans;
        sort(candidates.begin(), candidates.end());
        helper(0,target,arr,ans,candidates);
        return ans;
    }
};
class Solution {
private:
    void helper(int i, vector<int>& arr, vector<vector<int>>& ans, vector<int>& nums){
        ans.push_back(arr);
        for(int j=i;j<nums.size();j++){
            if(j>i && nums[j-1]==nums[j]) continue;
            arr.push_back(nums[j]);
            helper(j+1,arr,ans,nums);
            arr.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> arr;
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        helper(0,arr,ans,nums);
        return ans;
    }
};
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        /* because we need the subarrays in 
        the order --> bit masking */
        // 2^n = 1<<n
        int n= nums.size();
        int subsets= 1<<n;
        vector<vector<int>> ans;

        for(int i=0;i<subsets;i++){
             vector<int> arr;
             for(int j=0;j<n;j++){
                if(i & (1<<j)) arr.push_back(nums[j]); // set bit checker
             }
             ans.push_back(arr);
        }
        return ans;
    }
};
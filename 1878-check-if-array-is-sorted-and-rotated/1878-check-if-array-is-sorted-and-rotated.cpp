class Solution {
public:
    bool check(vector<int>& nums) {
        vector<int> arr = nums;
        int i;
        sort(arr.begin(),arr.end());
        for(i=1;i<nums.size();i++){
            if(nums[i]<nums[i-1]) break;
        }
        reverse(nums.begin(),nums.begin()+i);
        reverse(nums.begin()+i,nums.end());
        reverse(nums.begin(),nums.end());
        if(nums==arr) return true;
        return false;
    }
};
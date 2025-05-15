class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(k>nums.size()) k=(k%nums.size());
        int i = nums.size()-k; 
        reverse(nums.begin(),nums.begin()+i);
        reverse(nums.begin()+i,nums.end());
        reverse(nums.begin(),nums.end());
    }
};
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // only -ve case
        int maxi=nums[0];
        int j;
        for(j=0;j<nums.size();j++){
            if(nums[j]>=0) break;
            maxi=max(maxi,nums[j]);
        }
        if(j>=nums.size()) return maxi;
        // both +ve or -ve
        maxi=nums[0];
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum<0) sum=0;
            maxi=max(maxi,sum);
        }
        return maxi;
    }
};
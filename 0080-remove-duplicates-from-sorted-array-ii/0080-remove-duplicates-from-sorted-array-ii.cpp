class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        int j=1;
        int cnt=1;
        while(j<n){
            if(nums[j]==nums[i]){
                if(cnt>=2) j++;
                else {
                    cnt++;
                    swap(nums[i+1],nums[j]);
                    i++;
                    j++;
                }
            }
            else{
                swap(nums[i+1],nums[j]);
                i++;
                j++;
                cnt=1;
            }
        }
        return i+1;
    }
};
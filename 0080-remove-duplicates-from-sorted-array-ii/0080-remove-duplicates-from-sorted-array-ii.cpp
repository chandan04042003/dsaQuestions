class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        int j=1;
        int cnt=1;
        while(j<n){
            if(nums[j]==nums[i]){
                if(cnt<2){
                    cnt++;
                    swap(nums[i+1],nums[j]);
                    i++;
                }
            }
            else{
                swap(nums[i+1],nums[j]);
                i++;
                cnt=1;
            }
            j++;
        }
        return i+1;
    }
};
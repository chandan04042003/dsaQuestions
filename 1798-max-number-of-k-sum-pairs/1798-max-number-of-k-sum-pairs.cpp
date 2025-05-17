class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int cnt=0;
        int i=0;
        int j=nums.size()-1;
        while(i<j){
            int sum=nums[i]+nums[j];
            if(sum==k){
                i++;
                j--;
                cnt++;
            } 
            else if(sum<k) i++;
            else j--;
        }
        return cnt;
    }
};
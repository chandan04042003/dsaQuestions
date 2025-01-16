class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        int cnt=0;
        long long sum2=0;
        for(int i=0;i<n;i++){
            sum2+=nums[i];
        }
        long long sum1=0;
        for(int i=0;i<n;i++){
            sum1+=nums[i];
            sum2-=nums[i];
            if(sum1>=sum2 && i<n-1){
                cnt++;
            }
        }
        return cnt;
    }
};
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        long long preProd=1;
        long long sufProd=1;
        int i=0;
        int j=n-1;
        long long maxi=INT_MIN;
        while(i<n && j>=0){
            preProd*=nums[i];
            sufProd*=nums[j];
            maxi=max({maxi,preProd,sufProd});
            if(nums[i]==0) preProd=1;
            if(nums[j]==0) sufProd=1;
            i++;
            j--;
        }
        return (int)maxi;
    }
};
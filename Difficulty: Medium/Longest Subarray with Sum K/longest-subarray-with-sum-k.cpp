class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        unordered_map<int,int> mp;
        int sum=0;
        int maxi=0;
        mp[0]=-1; // edge case when sum==k
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
            int target=sum-k;
            if(mp.find(target)!=mp.end()){
                int ind=mp[target];
                maxi=max(maxi,i-ind);
            }
            if(mp.find(sum)==mp.end()) mp[sum]=i;
        }
        return maxi;
    }
};
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> vec;
        if(nums.size()==0) return vec;
        int next=nums[0];
        int i=0;
        while(i<nums.size()){
            string start=to_string(nums[i]);
            while(i+1<nums.size() && nums[i+1]==nums[i]+1) i++;
            string end=to_string(nums[i]);
            if(start==end) vec.push_back(start);
            else vec.push_back(start+"->"+end);
            i++;
        }
        return vec;
    }
};
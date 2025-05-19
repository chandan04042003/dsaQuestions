class Solution {
private:
    void divide(int l,int h,vector<int>& nums,int& cnt){
        if(l>=h) return;
        int mid=(l+h)/2;
        divide(l,mid,nums,cnt);
        divide(mid+1,h,nums,cnt);
        merge(l,mid,h,nums,cnt);
    }
    void merge(int l,int mid,int h,vector<int>& nums,int &cnt){
        int j=mid+1;
        int i = l;
        while (i <= mid && j <= h) {
            if ((long long)nums[i] > 2LL * nums[j]) {
                cnt += mid - i + 1;
                j++;
            } else {
                i++;
            }
        }

        // sorting
        i=l;
        j=mid+1;
        vector<int> vec;
        while(i<=mid && j<=h){
            if(nums[i]<=nums[j]){
                vec.push_back(nums[i]);
                i++;
            }
            else{
                vec.push_back(nums[j]);
                j++;
            } 
        }
        // left outs
        while(i<=mid){
            vec.push_back(nums[i]);
            i++;
        }
        while(j<=h){
            vec.push_back(nums[j]);
            j++;
        }
        for(int k=0;k<vec.size();k++){
            nums[l+k]=vec[k];
        }
    }
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        int cnt=0;
        divide(0,n-1,nums,cnt);
        return cnt;
    }
};
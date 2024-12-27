class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // Create a temporary vector
        vector<int> temp(m + n);
        int left = 0;
        int right = 0;
        int index = 0;
        
        // Merge elements from nums1 and nums2
        while (left < m && right < n) {
            if (nums1[left] <= nums2[right]) {
                temp[index] = nums1[left];
                left++;
                index++;
            } else {
                temp[index] = nums2[right];
                right++;
                index++;
            }
        }
        
        // Copy remaining elements from nums1
        while (left < m) {
            temp[index++] = nums1[left++];
        }
        
        // Copy remaining elements from nums2
        while (right < n) {
            temp[index++] = nums2[right++];
        }
        
        // Copy back to nums1
        for (int i = 0; i < m + n; i++) {
            nums1[i] = temp[i];
        }
    }
};
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        vector<int> min_left(n, INT_MAX);
        
        // Find minimum element to the left of each position
        for(int i = 1; i < n; i++) {
            min_left[i] = min(min_left[i-1], nums[i-1]);
        }
        
        stack<int> st; 

        for(int j = n-1; j >= 0; j--) {
            // If a 'j' has 'i' => i<j : nums[i]<nums[j]
            if(min_left[j] < nums[j]) {
                // nge for 'i'=>'k' i.e nums[i]<nums[k]
                while(!st.empty() && nums[st.top()] <= min_left[j]) {
                    st.pop();
                }
                
                // k=st.top();
                if(!st.empty() && nums[st.top()] < nums[j]) {
                    return true;
                }
            }
            st.push(j);
        }
        
        return false;
    }
};
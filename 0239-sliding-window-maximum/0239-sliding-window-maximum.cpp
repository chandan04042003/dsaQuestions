class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // monotonically decreasing deque
        deque<int> dq; // store indices
        vector<int> ans;

        for(int i = 0; i < k; i++) {
            while(!dq.empty() && nums[dq.back()] <= nums[i]) dq.pop_back();
            dq.push_back(i);
        }

        for(int i = k; i < nums.size(); i++) {
            ans.push_back(nums[dq.front()]);

            // pop if the front index is out of the current window
            if(dq.front() <= i - k) dq.pop_front();

            while(!dq.empty() && nums[dq.back()] <= nums[i]) dq.pop_back();
            dq.push_back(i);
        }

        ans.push_back(nums[dq.front()]);
        return ans;
    }
};

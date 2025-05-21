class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // nge=> monotonically decreasing stack ---> (only arr[i]<st.top() will
        // be added to the stack)
        int n2=nums2.size();
        unordered_map<int, int> nge;
        stack<int> st;
        for(int i=n2-1;i>=0;i--){
            while(!st.empty() && nums2[st.top()]<=nums2[i]) st.pop();
            nge[nums2[i]] = (st.empty() ? -1 : nums2[st.top()]);
            st.push(i);
        }
        int n1=nums1.size();
        vector<int> ans;
        for(int i=0;i<n1;i++){
            ans.push_back(nge[nums1[i]]);
        }
        return ans;
    }
};
class Solution {
private:
    void nse(vector<int>& heights,vector<int>& ans){
        stack<int> st;
        for(int i=heights.size()-1;i>=0;i--){
            while(!st.empty() && heights[st.top()]>=heights[i]) st.pop();
            if(!st.empty()) ans[i]=st.top();
            st.push(i);
        }
    }
    void pse(vector<int>& heights,vector<int>& ans){
        stack<int> st;
        for(int i=0;i<heights.size();i++){
            while(!st.empty() && heights[st.top()]>=heights[i]) st.pop();
            if(!st.empty()) ans[i]=st.top();
            st.push(i);
        }
    }
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> nseAns(n,n);
        vector<int> pseAns(n,-1);
        nse(heights,nseAns);
        pse(heights,pseAns);
        int maxi=0;
        for(int i=0;i<n;i++){
            int l=heights[i];
            int b=nseAns[i]-pseAns[i]-1;
            maxi=max(maxi,l*b);
        }
        return maxi;
    }
};
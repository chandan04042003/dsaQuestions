class Solution {
  public:
    vector<int> nextLargerElement(vector<int> &arr) {
        int n=arr.size();
        stack<int> st;
        vector<int> nge(n,-1);
        for(int i=2*n-1;i>=0;i--){
            if(i<n){
                while(!st.empty() && st.top()<=arr[i]) st.pop();
                if(!st.empty()) nge[i]=st.top();
                st.push(arr[i]);
            }
            else{
                int j=i%n;
                while(!st.empty() && st.top()<=arr[j]) st.pop();
                st.push(arr[j]);
            }
        }
        return nge;
    }
};
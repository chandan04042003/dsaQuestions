class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // monotically decreasing stack (nge) => 73,69,67...(to add in stack
        // arr[i] < st.top())
        stack<int> st;
        int n=temperatures.size();
        vector<int> nge(n,0);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && temperatures[st.top()]<=temperatures[i]){
                st.pop();
            }
            if(!st.empty()) nge[i]=st.top()-i; // for nge just add i
            st.push(i);
        }
        return nge;
    }
};
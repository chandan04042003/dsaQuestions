class Solution {
public:
    string removeKdigits(string num, int k) {
        // monotonically increasing stack 
        stack<char> st;
        for (char x : num) {
            while (!st.empty() && k>0 && st.top()>x) {
                st.pop();
                k--;
            }
            st.push(x);
        }

        // If k > 0, remove from the end
        while (k-- > 0 && !st.empty()) {
            st.pop();
        }

        string ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());

        // Remove leading zeros
        int i = 0;
        while (i < ans.size() && ans[i] == '0') {
            i++;
        }
        ans = ans.substr(i);

        return ans.empty() ? "0" : ans;
    }
};
class Solution {
public:
    string removeStars(string s) {
        int n= s.size();
        string ans;
        stack<char> st;
        for(int i=0;i<n;i++){
            if(s[i]=='*' && !st.empty()){
                st.pop();
                continue;
            }
            if(s[i]=='*') continue;
            st.push(s[i]);
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
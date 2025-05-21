class Solution {
public:
    string removeStars(string s) {
        stack<char> st;
        string ans;
        for(char x:s){
            if(x=='*') st.pop();
            else st.push(x);
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;      
    }
};
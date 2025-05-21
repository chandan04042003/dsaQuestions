class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        string ans;
        
        for(int i=0;i<s.size();i++){
            int f=0;
            while(!st.empty() && st.top()==s[i]){
                st.pop();
                f=1;
            } 
            if(f==0) st.push(s[i]);
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
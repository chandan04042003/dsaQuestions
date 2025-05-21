class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        // as we traverse each el and then check the stack , traverse on s
        for(char x:s){
            if(x=='(' || x=='{' || x=='['){
                st.push(x);
            }
            else{
                if(st.empty()) return false;
                char c=st.top();
                if((c=='(' && x==')') || (c=='{' && x=='}') || (c=='[' && x==']')){
                    st.pop();
                }
                else return false;
            }
        }
        return st.empty();
    }
};
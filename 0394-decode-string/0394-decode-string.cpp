class Solution {
public:
    string decodeString(string s){
        stack<char> st;
        for(char x:s){
            // for each char in s ---> alphabet / number(can be more than one digit) / [ / ]
            if(x==']'){
                string temp;
                while(st.top()!='['){
                    temp.push_back(st.top());
                    st.pop();
                }
                st.pop();
                reverse(temp.begin(),temp.end());
                // as guarenteed that number exists if there is []
                string num;
                while(!st.empty() && st.top()>='0' && st.top()<='9'){
                    num.push_back(st.top());
                    st.pop();
                }
                reverse(num.begin(),num.end());
                int n=stoi(num);
                // push back to stack to deal with nested loop (imp edge case)
                while (n--) { 
                    for (char ch : temp) {
                        st.push(ch);
                    }
                } 
            }
            else st.push(x);
        }
        string ans;
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
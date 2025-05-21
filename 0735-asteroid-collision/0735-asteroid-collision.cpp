class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        vector<int> ans;
        for(int x:asteroids){
            if(x>0){
                st.push(x);
            }
            else{
                while(!st.empty() && st.top()>0 && -x>st.top()) st.pop();
                if(!st.empty() && st.top()==-x){
                    st.pop();
                    continue;
                }
                if(st.empty() || st.top()<0) st.push(x);
            }
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
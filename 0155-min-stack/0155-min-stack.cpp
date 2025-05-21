class MinStack {
public:
    vector<pair<int,int>> st;
    int mini=INT_MAX;
    MinStack() {
    }
    
    void push(int val) {
        mini=min(mini,val);
        st.push_back({val,mini});
    }
    
    void pop() {
        st.pop_back();
        // imp
        if(!st.empty()) mini=st.back().second;
        else mini = INT_MAX; 
    }
    
    int top() {
        return st.back().first;
    }
    
    int getMin() {
        return st.back().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
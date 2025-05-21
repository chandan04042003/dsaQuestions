class StockSpanner {
    
public:
    vector<int> ans;
    stack<int> st;
    int i=0;
    StockSpanner(){
    }

    //previous greater element => monotonically decreasing
    int next(int price) {
        ans.push_back(price); 
        while (!st.empty() && ans[st.top()] <= price) st.pop();

        int val = st.empty() ? i + 1 : i - st.top();
        st.push(i);
        i++;
        return val;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
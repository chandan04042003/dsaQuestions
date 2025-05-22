class MyQueue {
public:
    stack<int> st1; // input stack
    stack<int> st2; // output stack

    MyQueue() {
    }

    void push(int x) {
        st1.push(x);
    }

    int pop() {
        if (st2.empty()) {
            while (!st1.empty()) {
                st2.push(st1.top());
                st1.pop();
            }
        }
        int val = st2.top();
        st2.pop();
        return val;
    }

    int peek() {
        if (st2.empty()) {
            while (!st1.empty()) {
                st2.push(st1.top());
                st1.pop();
            }
        }
        return st2.top();
    }

    bool empty() {
        return st1.empty() && st2.empty();
    }
};

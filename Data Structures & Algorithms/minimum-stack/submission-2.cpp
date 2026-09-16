
class MinStack {
    stack<int> st;
    stack<int> minSt;
public:
    MinStack() {
        // stack<int> st;
        // stack<int> minSt;
    }
    
    void push(int val) {
        st.push(val);
        if(minSt.empty()) {
            minSt.push(val);
        }
        else {
            if(val < minSt.top()) {
                minSt.push(val);
            }
            else {
                minSt.push(minSt.top());
            }
        }
    }
    
    void pop() {
        minSt.pop();
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minSt.top();
    }
};

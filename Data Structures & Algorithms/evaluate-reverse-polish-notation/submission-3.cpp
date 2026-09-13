class Solution {
public:
    int evalRPN(vector<string>& v) {
        stack<int> st;
        for(auto u :v) {
           char c = u[0];
            if(c == '+' and u.size() == 1) {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(a + b);

            }
            else if(c == '-' and u.size() == 1){
               int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(b - a);
            }
            else if(c == '*' and u.size() == 1){
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(a * b);
            }
            else if(c == '/' and u.size() == 1) {
                int a = st.top();
                st.pop();
                int b = st.top();
                cout << a << ' ' << b << '\n';
                st.pop();
                st.push(b / a);
            }
            else {
                st.push(stoll(u));
            }
        }
        return st.top();
    }
};

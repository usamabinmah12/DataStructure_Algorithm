class Solution {
public:
    bool isValid(string s) {
      stack<char> st;
      for(auto u : s) {
        if(!st.empty()) {
            if(u == ']' and st.top() == '[')  st.pop();
            else if(u == '}' and st.top() == '{')  st.pop();
            else if(u == ')' and st.top() == '(')  st.pop();
            else st.push(u);
        } 
        else st.push(u);


      }
      return st.size() == 0;  
    }
};

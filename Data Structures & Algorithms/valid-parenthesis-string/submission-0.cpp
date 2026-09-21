class Solution {
public:
    bool checkValidString(string s) {
        stack<int > st , ed , ast;
        int n = s.size();
        for(int i = 0;  i < n ; i++) {
            if(s[i] == '(') {
                st.push(i);
            }
            else if(s[i] == '*') {
                ast.push(i);
            }
            else {
                if(!st.empty()) {
                    st.pop();
                }
                else if(!ast.empty()) {
                    ast.pop();
                }
               else return false;
            }
        }
        while(!st.empty() and !ast.empty() and ast.top() > st.top()) {
            // cout << "usa\n";
            st.pop();
            ast.pop();
        }
        return st.size() == 0;














        // for(auto u : s) {
        //     if(u == '(') {
        //         st.push(u);
        //     }
        //     else if(u == '*') {
        //         ast++;
        //     }
        //     else (
        //         if(!st.empty()) {
        //             st.pop();
        //         }
        //         else if(ast > 0) {
        //             ast--;
        //         }
        //     )
        // }
    }
};

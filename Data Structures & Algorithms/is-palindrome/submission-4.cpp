class Solution {
public:
    bool isPalindrome(string str) {
        string s = "";
        int n = str.size();
        for(int i = 0 ;i < n ; i++) {
            // char c = str[i];
            if(str[i] >= 'A' and  str[i] <= 'Z') {
                s += ((str[i] - 'A') + 'a');
            }
            else {
                if((str[i] >= 'a' and str[i] <= 'z') or (str[i] >= '0' and str[i] <= '9'))  s += str[i];
            }
        }
        
        
        auto p = s;
       
        reverse(s.begin() ,s.end());
        cout << s << '\n';
        return p == s;
    }
};

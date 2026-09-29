class Solution {

public:
    string longestPalindrome(string s) {
        int n = s.size();
        int len = 0 ,st = 0;
        for(int i = 0 ; i < n ; i++) {
            int l = i  , r = i;
            while(l >= 0 and r < n and s[l] == s[r]) {
                if(r - l + 1 > len) {
                    st = l;
                    len = r - l + 1;
                }
                l--;
                r++;
            }
           
        }
        for(int i = 0 ; i < n -  1 ;  i++) {
            int l = i , r = i + 1;
             while(l >= 0 and r < n and s[l] == s[r]) {
                if(r - l + 1 > len) {
                    st = l;
                    len = r - l + 1;
                }
                l--;
                r++;
            }
            // if(r - l + 1 > len) {
            //     st = l;
            //     len = r - l + 1;
            // }
        }
        return s.substr(st , len);
    }
};

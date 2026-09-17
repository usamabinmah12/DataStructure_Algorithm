class Solution {
public:
    bool chk(map<char , int>&mp1 , map<char , int> &mp) {
        for(char c = 'A' ; c <= 'Z' ; c++) {
            if(mp1[c] < mp[c]) {
                return false;
            }
        }
         for(char c = 'a' ; c <= 'z' ; c++) {
            if(mp1[c] < mp[c]) {
                return false;
            }
        }
        return true;
    }
    string minWindow(string s1, string s2) {
        map<char , int > mp , mp1;
        for(int i = 0 ; i < s2.size() ; i++) {
            mp[s2[i]]++;
        }
        if(s2.size() > s1.size()) return "";
        int j = 0 ,n = s1.size();
        int ans = -1;
        int st = -1 , len  =INT_MAX;
        for(int i = 0; i < n ; i++) {
            
            while(j < n and !chk(mp1 , mp)) {
                mp1[s1[j]]++;
                j++;
            }
            if(chk(mp1 , mp)) {
                ans = i;
                if(j - i  < len) {
                    len = j - i ;
                    st = i;
                }
            }
            mp1[s1[i]]--;
        }
        if(ans == -1) return "";
        return s1.substr(st , len);
    }
};

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int r = 0,n = s.size() , ans =0;
        map<char , int>mp;
        for(int l = 0 ; l < n ; l++) {
            r = max(r  , l);
            while(r < n and mp[s[r]] < 1) {
               
                mp[s[r]]++;
                r++;
            }
            mp[s[l]]--;
            ans = max(ans , r - l);
            
        }
        return ans;
    }
};

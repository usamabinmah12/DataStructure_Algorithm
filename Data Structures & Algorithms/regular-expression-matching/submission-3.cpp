class Solution {
    vector<vector<int>>dp;
    bool dfs(int i , int j , string &s , string &p) {
        if(i >= s.size() and j >= p.size() ) return true;
        if(j >= p.size()) return false;
        // if(i >= s.size()) return false;
        if(dp[i][j] != -1) return dp[i][j];
        bool match = i < s.size() and ( p[j] == s[i] or  p[j] == '.');
        if(j + 1 < p.size() and p[j + 1] == '*') {
            return dp[i][j] =  dfs(i , j + 2 , s , p) or (match and dfs( i + 1 , j , s , p));
        }
        if(match) {
            return dp[i][j] =  dfs(i + 1 , j + 1  , s , p);
        }
        else return false;

    }
public:
    bool isMatch(string s, string p) {
        dp = vector<vector<int>>(25, vector<int> (25 , -1));
        bool ans = dfs(0 , 0 , s , p);
        return ans;
    }
};

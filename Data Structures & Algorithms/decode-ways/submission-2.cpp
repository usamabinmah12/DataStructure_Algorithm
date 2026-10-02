class Solution {
    vector<int> dp;
    int dfs(int i , string s) {
        if(i == s.size()) {
            return 1;

        }
        if(s[i] == '0') {
            return 0;
        }
        if(dp[i] != -1) {
            return dp[i];
        }
        int ans = dfs(i + 1 , s);
        if(i < s.size() - 1) {
            if(s[i] == '1' or( s[i] == '2' and s[i + 1] < '7')) {
                ans += dfs(i + 2 ,s);
            }
        }
        return dp[i]=ans;
    }
public:
    int numDecodings(string s) {
        int n = s.size();
        dp = vector<int> (n , -1);
        return dfs(0 , s);
    }
};

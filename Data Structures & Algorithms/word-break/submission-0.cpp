class Solution {
    int f = 0;
    bool dfs(int i , string s, vector<string>& wordDict , string curS) {
        cout << curS << '\n';
        if(curS == s) {
            f = 1;
            return true;
        }
        if(curS.size() > s.size()) return false;
        if(i == wordDict.size()) {
            return false;
        }
        
        bool ans = dfs(i , s , wordDict , curS + wordDict[i]) | dfs(i + 1 , s , wordDict , curS);
        return ans;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<int> dp(n + 1 , 0);
        dp[n] = 1;
        for(int i =n - 1 ; i >= 0 ; i--) {
            for(auto w :  wordDict) {
                if(i + w.size() <= n and w == s.substr(i , w.size())) {
                    dp[i] = dp[i + w.size()];
                }
                if(dp[i])  break;
            }

        }
        return dp[0];

    }
};

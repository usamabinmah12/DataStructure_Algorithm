class Solution {
    map<pair<int , string> , int> dp;
    int dfs(int i ,string cur , string &s, string &t ) {
        if(i == s.size()) {
            return cur == t;
        }
        auto p = make_pair(i , cur);
        if(dp.find(p) != dp.end()) {
            return dp[p];
        }
        int ans = dfs(i + 1  , cur + s[i] , s , t) + dfs(i + 1 , cur , s , t );
        return dp[p] = ans;
    }
public:
    int numDistinct(string s, string t) {
        dp.clear();
        int ans = dfs(0 , "" , s , t);
        return ans;
    }
};

class Solution {
    map<pair<int , string> , int> dp;
    int dfs(int i ,string cur , string &s, string &t ) {
        if(i == s.size()) {
            return cur.size() == 0;
            // return cur == t;
        }
        auto p = make_pair(i , cur);
        if(dp.find(p) != dp.end()) {
            return dp[p];
        }
        int ans = dfs(i + 1 , cur , s , t );
        if(cur.size() >= 1 and s[i] == cur.back()) {
            cur.pop_back();
            ans += dfs(i + 1 , cur , s , t);
            cur.push_back(s[i]);
        }
        return dp[p] = ans;
    }
public:
    int numDistinct(string s, string t) {
        dp.clear();
        reverse(s.begin() , s.end());
        int ans = dfs(0 , t , s ,t);
        return ans;
    }
};

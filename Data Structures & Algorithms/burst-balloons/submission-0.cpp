class Solution {
    vector<vector<int>> dp;
    int dfs(int l , int r , vector<int> &v) {
        if(l > r) {
            return 0;
        }
        if(dp[l][r] != -1) return dp[l][r];
        dp[l][r] = 0;
        for(int i = l ; i <= r ; i++) {
            int cur = v[l - 1] * v[i] * v[r + 1];
            cur += dfs(l , i - 1 , v) + dfs(i + 1 , r, v);
            dp[l][r] = max(cur , dp[l][r]);
        }
        return dp[l][r];
    }
public:
    int maxCoins(vector<int>& nums) {
        vector<int>v;
        v.push_back(1);
        for(auto u : nums) {
            v.push_back(u);

        }
        v.push_back(1);
        dp = vector<vector<int>> (v.size() , vector<int>(v.size(), -1));
        int ans = dfs(1 , v.size() - 2 , v);
        return ans;
    }
};

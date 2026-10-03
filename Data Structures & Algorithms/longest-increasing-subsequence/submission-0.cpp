class Solution {
public:
    int lengthOfLIS(vector<int>& v) {
        int n = v.size();
        vector<int> dp(n , 1);
        // dp[n - 1] =  1;
        int ans = 1;
        for(int i = n - 1; i >= 0 ; i--) {
            int cur = 0;
            for(int j = i + 1 ; j < n ; j++) {
                if(v[i] < v[j]) {
                    cur = max(cur ,1 + dp[j]);
                    ans = max(ans, cur);
                    // break;
                }
            }
            dp[i] = max(cur , dp[i]);

            
        }
        return ans;
    }
};

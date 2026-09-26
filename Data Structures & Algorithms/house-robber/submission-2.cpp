class Solution {
    int  n;
    vector<int> g;
   vector<int>dp;
    int rec(int i ) {
        if(i >= n) {
            return 0;
        }
        if(dp[i] != -1) {
            return dp[i];
        }
       int ans = rec(i + 1);
    
       ans = max(g[i] + rec(i + 2) , ans);
  
    
       return dp[i] = ans;
    }

public:
    int rob(vector<int>& v) {
       
        n = v.size();
        g = v;
        dp =  vector<int>(n,-1);
        // dp.assign(n , vector<int> (2 ,-1));
        // int ans = rec(0);
        int ans[n];
        for(int i = 0 ; i < n ; i++) {
            if(!i) {
                ans[0] = v[0];
            }
            else if(i ==1) {
                ans[1] = max(ans[0] , v[1]);
            }
            else {
                ans[i] = max(v[i] + ans[i-2] , ans[i -  1]);
            }
        }
        return ans[n - 1];
    }
};

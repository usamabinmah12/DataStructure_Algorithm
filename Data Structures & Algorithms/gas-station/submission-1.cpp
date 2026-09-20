class Solution {
public:
    int canCompleteCircuit(vector<int>& g, vector<int>& c) {
        int n = g.size();
        int cur = 0;
        vector<int> v(n);
        for(int i = 0 ; i < n ; i++) {
            cur += (g[i] - c[i]);
            v[i] = (g[i] - c[i]);
        }
        if(cur < 0) return -1;
        cur = 0;
        int ans = n - 1;
        for(int i = n - 1 ; i >= 0 ; i--) {
            if(v[i] + cur >= 0 and v[i] >= 0) {
                
                ans = i;
                cur = 0;
            }
            else {
                cur += v[i];
            }
        }
        return ans;
        
    }
};

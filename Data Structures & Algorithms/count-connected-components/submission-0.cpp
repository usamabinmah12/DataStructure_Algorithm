class Solution {
    vector<int> vis;
    vector<vector<int>> gp;
    void dfs(int r) {
        vis[r] = 1;
        for(int c : gp[r]) {
            if(!vis[c]) {
                dfs(c);
            }
        }
        
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        gp = vector<vector<int>>(n);
        vis = vector<int> (n , 0);
        int ans= 0;
        for(auto u : edges) {
            gp[u[0]].push_back(u[1]);
            gp[u[1]].push_back(u[0]);
        }
        for(int i = 0 ; i < n ; i++) {
            if(vis[i] == 0) {
            
                ++ans;
                dfs(i);
            }
        }
        return ans;
    }
};

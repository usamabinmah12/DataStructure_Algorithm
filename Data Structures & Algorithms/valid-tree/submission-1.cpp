class Solution {
    vector<vector<int>> gp;
    vector<int> vis;
    bool ans = true;
    void dfs(int ch , int parent) {
        vis[ch] = 1;
        // bool cur = 0;
        for(auto u : gp[ch]) {
            if(u != parent and vis[u]) {
                cout <<u << ' ' << ch << '\n';
                ans = false;
                return ;
            }
            if(u != parent) {
               dfs(u , ch);
            }
        }
        // return true;
    }
public:
    bool validTree(int n, vector<vector<int>>& ed) {
        gp = vector<vector<int>>(n);
        vis =  vector<int> (n);
        for(auto u : ed) {
            gp[u[0]].push_back(u[1]);
            gp[u[1]].push_back(u[0]);
        }
        // bool ans = true;
        dfs(0 , -1);
        for(int i = 0 ; i < n;  i++) {
            if(!vis[i]) {
               return false;
            }
        }
        return ans;

    }
};

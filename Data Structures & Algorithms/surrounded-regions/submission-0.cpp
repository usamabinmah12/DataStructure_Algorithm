class Solution {
    int n , m;
    vector<vector<int>> vis;
    void dfs(int i , int j, vector<vector<char>>& v) {
        if(i <0 or j < 0 or j >= m or i >= n) return;
        if(vis[i][j] or v[i][j] == 'X') return;
        vis[i][j] = 1;
        dfs(i + 1, j , v);
        dfs(i - 1, j , v);
        dfs(i , j + 1 , v);
        dfs(i , j - 1, v);
    }
public:
    void solve(vector<vector<char>>& v) {
        n = v.size();
        m = v[0].size();
        vis.assign(n , vector<int>(m , 0));
        for(int i = 0 ; i < n ; i++) {
            dfs(i , 0 , v);
            dfs(i , m - 1 , v);
        }
        for(int j =0 ; j < m ; j++) {
            dfs(0 , j , v);
            dfs(n - 1 , j, v);
        }
        for(int i = 0 ; i < n ; i++) {
            for(int j =0  ; j < m ; j++) {
                if(!vis[i][j]) {
                    v[i][j] = 'X';
                }
            }
        }
    }
};

class Solution {
    int n , m;
    static const int N = 1e2 + 12;
    int vis[N][N];
public:
    void rec(vector<vector<char>>& g ,int i , int j) {
        if(i < 0 or i >= n or j < 0 or j >= m) return;
        if(g[i][j] == '0' or vis[i][j] == 1) return;
        vis[i][j] = 1;
        rec(g ,i + 1 , j);
        rec(g ,i - 1 , j);
        rec(g ,i , j+ 1);
        rec(g ,i , j - 1);

    }
    int numIslands(vector<vector<char>>& g) {
        n = g.size();
        m = g[0].size();
        int ans = 0;
        for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < m ; j++) {
            vis[i][j] = 0;
        }
       } 
       for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < m ; j++) {
            if(g[i][j] == '1' and vis[i][j] == 0) {
                rec( g , i , j);
                ans++;
            }
        }
       } 
       return ans;
    }
};
